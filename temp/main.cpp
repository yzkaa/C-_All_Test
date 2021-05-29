// File Name:main.cpp
// Date:     2019-07-09
// Copyright (C) 2019 UNISOC Technologies Co.,Ltd. All Rights Reserved

#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <cassert>
#include <cstring>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <algorithm>
#include "test_utils.h"
#include "unisocai.h"
#include <signal.h>

#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
//#include "logger.h"

#ifdef __LINUX__
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#else
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#endif

#define LOG_TAG "UNISOC_AISDK"
#define FLOAT32 "float32"
#define Q8A "Q8A"

#define LBBOX_FEATURE_MAP_SIZE 13//19//13
#define LBBOX_CELL LBBOX_FEATURE_MAP_SIZE * LBBOX_FEATURE_MAP_SIZE
#define MBBOX_FEATURE_MAP_SIZE 26//38//26
#define MBBOX_CELL MBBOX_FEATURE_MAP_SIZE * MBBOX_FEATURE_MAP_SIZE
#define SBBOX_FEATURE_MAP_SIZE 52//76//52
#define SBBOX_CELL SBBOX_FEATURE_MAP_SIZE * SBBOX_FEATURE_MAP_SIZE
#define NUM_CLASSES 80 
#define GT_PER_GRID 3
// a bunding box size = GT_PER_GRID * (coordinate + confidence + NUM_CLASSES)
#define BOX_SIZE GT_PER_GRID * (4 + 1 + NUM_CLASSES)
#define LBBOX_COUNT LBBOX_CELL * GT_PER_GRID
#define MBBOX_COUNT MBBOX_CELL * GT_PER_GRID
#define SBBOX_COUNT SBBOX_CELL * GT_PER_GRID
#define INPUT_SIZE 416

#define OUTPUT_SIZE_W 800
#define OUTPUT_SIZE_H 600

typedef struct {
  float x;
  float y;
  float h;
  float w;
  float has_object;
  int top_index;
  float top_score;
} box_t;

float confidence_threshold_ = 0.3f;
float iou_threshold_ = 0.40f;
unsigned top_n_ = 30;//   max support 最大输出box数量
std::vector<box_t> truth_box_;
int truth_box_count_ = 0;
size_t label_count_; // long unsigned int
std::vector<std::string> vec_labels_;
float img_ratio = 1; //图片缩放比例
float width_ratio_offset = 0; //图像偏移补偿
float height_ratio_offset = 0;

cv::Mat imgbase;//xiaoyao

TestCli cli;

template <class T>
void hwc_to_chw(T* dst, T* src, int height, int width, int channel) {
  /*
  T* input_data = reinterpret_cast<float*>
                   (malloc(sizeof(T) * channel * height * width));
  memcpy(reinterpret_cast<void*>(input_data),           // dest
         reinterpret_cast<const void*>(src),   // source
         sizeof(T) * channel * height * width);
  */
  for (int cc = 0; cc < channel; cc++) {
    for (int hw = 0; hw < (width * height); hw++) {
      // dst[hw * channel + cc] = src[cc * height * width + hw] / 255.0;
      dst[cc * height * width + hw] = src[hw * channel + cc] / 255.0;
    }
  }
}

template <class T>
void get_img(T* imgData_buffer,           /* [out] input buffer */
             std::string image_name,      /* [in] image file path */
             size_t shape[],              /* [in] input shape */
             bool is_nhwc = false,        /* [in] true: NHWC; false: NCHW */
             bool is_bgr_mode = false) {  /* [in] true: BGR; false: RGB */
  /* default: NCHW: 1 2 3 */
  int wanted_channels = shape[1];
  int wanted_height = shape[2];
  int wanted_width = shape[3];
  if (is_nhwc) {
    /* NHWC */
    wanted_height = shape[1];
    wanted_width = shape[2];
    wanted_channels = shape[3];
  }

  auto cv_fc3 = CV_8UC3;
  auto cv_fc1 = CV_8UC1;
  if (typeid(T) == typeid(float)) {
    cv_fc3 = CV_32FC3;
    cv_fc1 = CV_32FC1;
  }

  auto cv_fc = cv_fc3;
  if (wanted_channels == 1) {
    cv_fc = cv_fc1;
  }
  // Step#1: read image from file: -> img(BGR)
  //cv::Mat img = cv::imread(image_name, cv::IMREAD_COLOR);
  cv::Mat img = imgbase;

  if (img.empty()) {
    std::cout << "OpenCV::imread error! - read " << image_name << std::endl;
    return;
  }

  // Step#2: img(BGR) -> sample(RGB/BGR)
  cv::Mat sample;
  //std::cout << "wanted_channels: " <<wanted_channels<< ", image channels: " << img.channels() << std::endl;
  if (wanted_channels == 1) {
    // -> Gray
    if (img.channels() == 3) {
      cv::cvtColor(img, sample, cv::COLOR_BGR2GRAY);
    } else if (img.channels() == 4) {
      cv::cvtColor(img, sample, cv::COLOR_BGRA2GRAY);
    } else {
      sample = img;
    }
  } else if (wanted_channels == 3) {
    // -> RGB/BGRinc/logger.h:61:12: 
    if (img.channels() == 4) {
      auto colorConv = cv::COLOR_BGRA2RGB;
      if (is_bgr_mode) {
        colorConv = cv::COLOR_BGRA2BGR;
      }
      cv::cvtColor(img, sample, colorConv);
    } else if (img.channels() == 1) {
      auto colorConv = cv::COLOR_GRAY2RGB;
      if (is_bgr_mode) {
        colorConv = cv::COLOR_GRAY2BGR;
      }
      cv::cvtColor(img, sample, colorConv);
    } else if (img.channels() == 3) {
      if (is_bgr_mode) {
        sample = img;
      } else {
        cv::cvtColor(img, sample, cv::COLOR_BGR2RGB);
      }
    } else {
        std::cout << "wanted_channels: " <<wanted_channels
                  << ", Unknown channels: " << img.channels() << std::endl;
    }
  } else if (wanted_channels == 4) {
    // -> RGBA/BGRA
    if (img.channels() == 4) {
      if (is_bgr_mode) {
        sample = img;
      } else {
        cv::cvtColor(img, sample, cv::COLOR_BGRA2RGBA);
      }
    } else if (img.channels() == 1) {
      auto colorConv = cv::COLOR_GRAY2RGBA;
      if (is_bgr_mode) {
        colorConv = cv::COLOR_GRAY2BGRA;
      }
      cv::cvtColor(img, sample, colorConv);
    } else if (img.channels() == 3) {
      auto colorConv = cv::COLOR_BGR2RGBA;
      if (is_bgr_mode) {
        colorConv = cv::COLOR_BGR2BGRA;
      }
      cv::cvtColor(img, sample, colorConv);
    } else {
      std::cout << "wanted_channels: " <<wanted_channels
                << ", Unknown channels: " << img.channels() << std::endl;
    }
  } else {
      // Other channels?
      std::cout << "Unknown Wanted Channels " << wanted_channels << std::endl;
  }


  // Step#3 resize:sample(RGB/BGR) -> img_resized(wanted_height x wanted_width)
  cv::Mat img_resized;

//printf("*************************%d %d %d %d \r\n",img.rows,img.cols,wanted_height,wanted_width);
  if (img.rows != static_cast<int>(wanted_height)
      || img.cols != static_cast<int>(wanted_width)) {
    cv::Mat img_tmp;
    img_ratio = std::min((1.0f * wanted_width) / (1.0f * img.cols),
                         (1.0f * wanted_height)/ (1.0f * img.rows));
    int nw = static_cast<int>(img_ratio * img.cols);
    int nh = static_cast<int>(img_ratio * img.rows);
    if (sample.channels() == static_cast<int>(wanted_channels)) {
      std::cout << "image " << image_name << " size is NOT matched!\n"
              << "input should be :[" << wanted_channels << ", "
              << wanted_height << ", "<< wanted_width << "], "
              << "now input is :[" << img.channels() << ", "
              << img.cols <<", " << img.rows << "].\n"
              << "img is going to resize!" << std::endl;
      //std::cout << "resize to (" << nw << ", " << nh << ")" << std::endl;
      cv::resize(sample, img_tmp, cv::Size(nw, nh));
  if (img_tmp.empty()) {
      	std::cout << "^^^^^^^^^^^^^^^^^^^^*******^^^OpenCV::imread img_tmp error! - read "  << std::endl;
    	return;
  }
      int top = (wanted_height - nh) / 2;
      auto bottom = top;
      height_ratio_offset = top;
      if ((top + bottom + nh) < wanted_height) bottom++;

      int left = (wanted_width - nw) / 2;
      auto right = left;
      width_ratio_offset = left;
      if ((left + right + nw) < wanted_width) right++;
      cv::copyMakeBorder(img_tmp, img_resized, top, bottom, left, right,
                         cv::BORDER_CONSTANT, 127.5);
      /*std::cout << "fill img to (" << img_resized.channels() << ", "
                << img_resized.cols << ", "
                << img_resized.rows << ")" << std::endl;*/
    } else {
      std::cout << "Channels is NOT equal, wanted_channels: " <<wanted_channels
                << ", img channels: " << sample.channels() << std::endl;
    }
  } else {
    img_resized = sample;
  }


  // Step#4: convert to float: img_resized -> img_float
  cv::Mat img_float;
  if (typeid(T) == typeid(float)) {
    //std::cout << "cv::Convert to float (wanted_channels = "<< wanted_channels << ")" << std::endl;
    img_resized.convertTo(img_float, cv_fc);

  } else {
    // for uint8_t, no need convert to float
    img_float = img_resized;
  }

  // Step#5: img_float -> imgData_buffer
  T *input_data = reinterpret_cast<T*>(imgData_buffer);

  if (!is_nhwc) {
    /* NCHW: */
    //std::cout << "*** NCHW mode ***" << std::endl;
    // Step#5-1: input_data <-> input_img
    hwc_to_chw<T>(imgData_buffer, reinterpret_cast<T*>(img_float.data),
                  wanted_height, wanted_width, wanted_channels);
  } else {
    /* NHWC */
    //std::cout << "*** NHWC mode ***" << std::endl;
    if (img_float.isContinuous()) {
      //std::cout << "isContinuous: dirrectly copy data" << std::endl;
      memcpy(reinterpret_cast<void*>(input_data),           // dest
             reinterpret_cast<const void*>(img_float.data),   // source
             sizeof(T) * wanted_channels * wanted_height * wanted_width);
    } else {
      //std::cout << "is not Continuous: copy data per row" << std::endl;
      for (int j = 0; j < wanted_height; j++) {
        T* data_ptr = img_float.ptr<T>(j);
        memcpy(reinterpret_cast<void*>(input_data),       // dest
               reinterpret_cast<const void*>(data_ptr),   // source
               sizeof(T) * wanted_channels * wanted_width);
        input_data += wanted_channels * wanted_width;
      }
    }
    // In YoloV3, we need to convert data to [0-1] range
    //std::cout << "convert image data to [0-1]" << std::endl;
    input_data = imgData_buffer;
    for (int i = 0; i < wanted_channels * wanted_height * wanted_width;
         i++) {
      *input_data = *input_data / 255.0;
      input_data++;
    }
  }
  return;
}

int ReadLabelsFile(const std::string& file_name,
                   std::vector<std::string>* result,
                   size_t* found_label_count) {
  std::ifstream file(file_name);
  if (!file) {
    std::cout << "read label file: " << file_name.c_str()
              << "failed" << std::endl;
    return -1;
  }
  result->clear();
  std::string line;
  while (std::getline(file, line)) {
    result->push_back(line);
  }
  *found_label_count = result->size();
  const int padding = 16;
  while (result->size() % padding) {
    result->emplace_back();
  }
  return 0;
}

inline float sigmoid(const float x) {
  return static_cast<float>(1.0 / (1.0 + std::exp(-x)));
}

void setBoxVaule(float buf[], int box_count, box_t box[]) {
  unsigned box_index = 0;
  float* buf_tmp = reinterpret_cast<float*>
                   (malloc(box_count * BOX_SIZE * sizeof(float)));
  // imgtec NNA output is NCHW 1*BOX_SIZE*h*w, need transpose
  int h = std::sqrt(box_count);
  auto w = h;
#if 1 // if use nchw mode, this should unmask
  for (int hw = 0; hw < box_count; hw++) {
    for (int cc = 0; cc < BOX_SIZE; cc++) {
      buf_tmp[hw*BOX_SIZE + cc] = buf[cc*h*w + hw];
    }
  }
  buf = buf_tmp;
#endif
  for (int i = 0; i < box_count; i++) {
    for (int j = 0; j < GT_PER_GRID; j++) {
      box[box_index].x = *buf;
      box[box_index].y = *(buf+1);
      box[box_index].w = *(buf+2);
      box[box_index].h = *(buf+3);
      box[box_index].has_object = sigmoid(*(buf+4));
      buf += 5; // 指针移位
      box[box_index].top_score = -1000.0;
      box[box_index].top_index = -1;
      if (box[box_index].has_object < confidence_threshold_) {
        buf += NUM_CLASSES; // 指针移位
        box_index++;
        continue;
      }
      for (unsigned k = 0; k < NUM_CLASSES; k++) {
        float score = sigmoid(*buf);
        if (score > box[box_index].top_score) {
          box[box_index].top_index = k;
          box[box_index].top_score = score;
        }
        buf++;
      }
      box_index++;
    }
  }
  free(buf_tmp);
}

// Implement the intersection over union (IoU) between box1 and box2
// Arguments:
// box1 -- first box, list object with coordinates (x1, y1, x2, y2)
// box2 -- second box, list object with coordinates (x1, y1, x2, y2)
float doIoU(box_t box1, box_t box2) {
  // Calculate the (y1, x1, y2, x2) coordinates
  // Which is intersection of box1 and box2, and calculate its area.
  float xi1 = std::max(box1.x, box2.x);
  float yi1 = std::max(box1.y, box2.y);
  float xi2 = std::min(box1.w, box2.w);
  float yi2 = std::min(box1.h, box2.h);
  float inter_area = (yi2 - yi1) * (xi2 - xi1);

  // Calculate the union area: Union(A,B) = A + B - Inter(A,B)
  float box1_area = (box1.w - box1.x) * (box1.h - box1.y);
  float box2_area = (box2.w - box2.x) * (box1.h - box2.y);
  float union_area = box1_area + box2_area - inter_area;

  // compute the IoU
  float iou = inter_area / union_area;

  return iou;
}

void doNMS(std::vector<box_t>* boxes, float iou_threshold) {
  // Calculate the (y1, x1, y2, x2) coordinates
  // Which is intersection of box1 and box2, and calculate its area.
  for (std::vector<box_t>::iterator it1 = boxes->begin();
       it1 != boxes->end(); it1++) {
    auto it2 = it1 + 1;
    while (it2 != boxes->end()) {
      float iou = doIoU(*it1, *it2);
      // compare the iou, if it is > threshold then discart it2
      if (iou > iou_threshold) {
        it2 = boxes->erase(it2);
      } else {
        it2++;
        // std::cout << "Next Obj[" << j << "]: iou: "
        // << iou << ", with " << i << ", valid!";
      }
    }  // for (it2 && j)
  }
}

void processBbox(box_t box[], unsigned box_count,
                  unsigned anchors[3][2], unsigned stride) {
  // std::cout << "start process boxes" << std::endl;
  unsigned dim = (unsigned)std::sqrt(box_count / 3);
  for (unsigned i = 0; i < box_count; i++)   {
    // each bunding box has three box, and bunding
    // count = feature_map_size * feature_map_size
    // std::cout << "calc boxes location" << std::endl;
    if (box[i].has_object < confidence_threshold_) {
      continue;
    }
    unsigned row_offset = (i / 3) / dim;
    unsigned col_offset = (i / 3) % dim;
    float tx = box[i].x;
    float ty = box[i].y;
    float tw = box[i].w;
    float th = box[i].h;

    auto anchor_box_w = anchors[i%3][0];
    auto anchor_box_h = anchors[i%3][1];
    // tx, ty, tw, th is the x,y,w,h's output offset,
    // then convert it on yolov3_height * yolov3_width
    auto bx = (sigmoid(tx) + col_offset + 1) * stride;
    auto by = (sigmoid(ty) + row_offset + 1) * stride;
    auto bw = anchor_box_w * std::exp(tw);
    auto bh = anchor_box_h * std::exp(th);
    // x0,y0,x1,y1 is the coordinate on yolov3_height * yolov3_width
    auto x0 = bx - bw / 2;
    auto y0 = by - bh / 2;
    auto x1 = bx + bw / 2;
    auto y1 = by + bh / 2;
    // convert x0,y0,x1,y1's coordinate to yolov3_height * yolov3_width's ratio,
    // so should subtraction the offset, if image height size is equal to height
    // size, the height ratio offset is 0, same as width ratio offset.
    x0 -= width_ratio_offset;
    y0 -= height_ratio_offset;
    x1 -= width_ratio_offset;
    y1 -= height_ratio_offset;
    // zoom in the yolov3 image to original size
    // if image size is equal to (height size * width size), img_ratio = 1
    x0 *= (1 / img_ratio);
    y0 *= (1 / img_ratio);
    x1 *= (1 / img_ratio);
    y1 *= (1 / img_ratio);
    // std::cout << "push current box to truth boxes" << std::endl;
    box[i].x = x0;
    box[i].y = y0;
    box[i].w = x1;
    box[i].h = y1;
    truth_box_.push_back(box[i]);
    // std::cout << "Get the " << truth_box_.size() <<" truth box" << std::endl;
  }
}

// Returns the top N confidence values over threshold in the provided vector,
// sorted by confidence in descending order.
void sortBox(std::vector<box_t>* sort_boxes, std::vector<box_t>* truth_boxes,
             size_t top_n, float threshold) {
  if (top_n == 0) {
    top_n = truth_boxes->size();
    //std::cout << "Get Top " << top_n << " results" << std::endl;
  }

  // Will contain top N results in ascending order.
  std::vector<box_t>::iterator it1 = truth_boxes->begin();
  while (it1 != truth_boxes->end()) {
    // Only add it if it beats the threshold and has a chance at being in
    // the top N.
    if (it1->top_score < threshold) {
      continue;
    }
    int top_idx = 0;
    float top_score = it1->top_score;
    for (unsigned j = 1; j < truth_boxes->size(); ++j) {
      if (top_score < (*truth_boxes)[top_idx].top_score) {
        top_idx = j;
        top_score = (*truth_boxes)[top_idx].top_score;
      }
    }
    (*sort_boxes).push_back((*truth_boxes)[top_idx]);
    truth_boxes->erase(truth_boxes->begin() + top_idx);
    it1 = truth_boxes->begin();
    // if top_n is less than truth boxes size, just get top_n and return.
    if (sort_boxes->size() > top_n) {
      sort_boxes->pop_back();
      return;
    }
  }
}


void showRec(){//my show
    for (unsigned i = 0; i < truth_box_.size() && i < top_n_; i++) {
      unsigned class_idx = truth_box_[i].top_index;
	if(truth_box_[i].x <= 0) truth_box_[i].x = 1;
	if(truth_box_[i].y <= 0) truth_box_[i].y = 1;
	if(truth_box_[i].w >= OUTPUT_SIZE_W ) truth_box_[i].w = OUTPUT_SIZE_W -1;	
	if(truth_box_[i].h >= OUTPUT_SIZE_H ) truth_box_[i].h = OUTPUT_SIZE_H -1;
  // x1 = x - w/2
  // y1 = y - h/2
  // x2 = x + w/2
  // y2 = y + h/2
		cv::Rect rect(truth_box_[i].x , truth_box_[i].y, truth_box_[i].w-truth_box_[i].x, truth_box_[i].h-truth_box_[i].y);//左上坐标（x,y）和矩形的长(x)宽(y)
        	cv::putText(imgbase, vec_labels_[class_idx], cv::Point(truth_box_[i].x,truth_box_[i].h-10), cv::FONT_HERSHEY_COMPLEX, 0.6, (255, 255, 255), 2,8,0);
        	cv::rectangle(imgbase, rect, cv::Scalar(66, 229, 119),2, 8 ,0);//green   
    }
  cv::imshow("test", imgbase);
  cv::waitKey(1);

}

// bbox value: (x, y, w, h, conf, prob), each feature cell has 3 boxes.
// bytes = channel * (coordinate + conf + class) * 3 * sizeof(float)
// the conv filter is bigger, the feature map cell is less.
// lbbox: size = LBBOX_CELL * BOX_SIZE * sizeof(float)
// mbbox: size = MBBOX_CELL * BOX_SIZE * 3 * sizeof(float)
// sbbox: size = SBBOX_CELL * BOX_SIZE * 3 * sizeof(float)
void handleDetectResult(float* lbbox_buf, float* mbbox_buf, float* sbbox_buf) {
  unsigned strides[3] = {32, 16, 8};

  unsigned anchors_l[3][2] = {{116, 190}, {156, 198}, {373, 326}};
  unsigned anchors_m[3][2] = {{30, 61}, {62, 45}, {59, 119}};
  unsigned anchors_s[3][2] = {{10, 13}, {16, 30}, {33, 23}};

  /* SSD post-processor */
  // location: float[NUM_RESULTS][4];
  box_t lbbox[LBBOX_COUNT];
  box_t mbbox[MBBOX_COUNT];
  box_t sbbox[SBBOX_COUNT];

  // 1. copy data into lbbox & mbbox & sbbox
  float *pOutput0 = lbbox_buf;
  float *pOutput1 = mbbox_buf;
  float *pOutput2 = sbbox_buf;
  setBoxVaule(pOutput0, LBBOX_CELL, lbbox);
  setBoxVaule(pOutput1, MBBOX_CELL, mbbox);
  setBoxVaule(pOutput2, SBBOX_CELL, sbbox);

  // 2. process bunding box anchors, get truth coordinates.
  processBbox(lbbox, LBBOX_COUNT, anchors_l, strides[0]);
  processBbox(mbbox, MBBOX_COUNT, anchors_m, strides[1]);
  processBbox(sbbox, SBBOX_COUNT, anchors_s, strides[2]);

  if (imgbase.empty()) {
    std::cout << "handle OpenCV::imread error! - read "  << std::endl;
    return;
  }

  if (truth_box_.size() > 1) {
    // 3. sort the truth boxes, get the top_n boxes.
    // std::vector<box_t> sorted_box;
    // if the top_n is 0, sort all boxes.
    // sortBox(&sorted_box, &truth_box_, 0, confidence_threshold_);
    // replace std::sort with sortBox, in this func, used lambda expression
    std::sort(truth_box_.begin(), truth_box_.end(), [](box_t a, box_t b){
      return a.top_score > b.top_score;
    });

    // 4. nms &
    // 5. print result
    std::cout << "Execute Result:"<< std::endl;
    doNMS(&truth_box_, iou_threshold_);
  }
  showRec();  
}

static int keepRunning = 1; 

void sig_handler( int sig )
{
    if ( sig == SIGINT)
    {
	  keepRunning = 0;
	  printf("sig_handler!!");
    }
}

int main(int argc, char* argv[]) {
  // get AISDK version
  unsigned int sdkverlen = GetSDKVersionLength();
  char* sdkver = reinterpret_cast<char*>(malloc(sdkverlen));
std::cout << LOG_TAG << " xiaoyao "<< std::endl;
  if (sdkver) {
    GetSDKVersion(sdkver);
    std::cout << LOG_TAG << " Version : " << sdkver << std::endl;
    std::free(sdkver);
  } else {
    std::cout << LOG_TAG << " Get SDK Version fail" << std::endl;
    return -1;
  }

  // parse cmdline
  cli.Parse(argc, argv);
  // 1. create model manager
  std::cout << LOG_TAG << " create model manager  " << std::endl;
  struct timeval init;
  gettimeofday(&init, nullptr);
  ModelMgr* modelManager = CreateModelManager();
  if (!modelManager) {
    std::cout << LOG_TAG << " ModelManager is nullptr " << std::endl;
    return -1;
  }
  struct timeval initend;
  gettimeofday(&initend, nullptr);
  double elapsedinit = (initend.tv_sec - init.tv_sec) * 1000.0 +
                       (initend.tv_usec - init.tv_usec) / 1000.0;
  std::cout << LOG_TAG << " Elapsed_Time for InitEnv : " << elapsedinit
            << std::endl;
  // 2. load model
  struct timeval loadmodel;
  gettimeofday(&loadmodel, nullptr);
  std::cout << LOG_TAG << " load Model " << cli.modelfile().c_str()
            << std::endl;
  int ret = LoadModel(modelManager, cli.modelfile().c_str(), HIGH_PERF);
  if (ret != AI_SUCCESS) {
    std::cout << LOG_TAG << " load model fail " << std::endl;
    return -1;
  }
  struct timeval loadmodelend;
  gettimeofday(&loadmodelend, nullptr);
  double elapsedload = (loadmodelend.tv_sec - loadmodel.tv_sec) * 1000.0 +
                       (loadmodelend.tv_usec - loadmodel.tv_usec) / 1000.0;
  std::cout << LOG_TAG << " Elapsed_Time for LoadModel: " << elapsedload
            << std::endl;

  // 3. input image files/buffers;
  DataFormat dataformat;
  InitDataFormat(&dataformat);
  dataformat.input_type = AISDK_FLOAT32;
  dataformat.output_type = AISDK_FLOAT32;

  dataformat.input_node_count = 1;
  dataformat.output_node_count = 3;

  char input_node_name[] = "yolov3/net1";
  char output_node_name0[] = "yolov3/convolutional59/BiasAdd";
  char output_node_name1[] = "yolov3/convolutional67/BiasAdd";
  char output_node_name2[] = "yolov3/convolutional75/BiasAdd";

  NodeShape* input_node =
             reinterpret_cast<NodeShape*>(malloc(sizeof(NodeShape)));
  input_node->node_dim_size = 4;
  input_node->node_name =
              reinterpret_cast<char*>(malloc(strlen(input_node_name)+1));
  snprintf(input_node->node_name, (strlen(input_node_name)+1),
           "%s", input_node_name);
  input_node->node_shape[0] = 1;
  input_node->node_shape[1] = INPUT_SIZE;
  input_node->node_shape[2] = INPUT_SIZE;
  input_node->node_shape[3] = 3;
  dataformat.input_nodes = &input_node;
  std::cout << LOG_TAG << " input node name: "
            << dataformat.input_nodes[0]->node_name << std::endl;
  NodeShape* outnode0 = reinterpret_cast<NodeShape*>(malloc(sizeof(NodeShape)));
  NodeShape* outnode1 = reinterpret_cast<NodeShape*>(malloc(sizeof(NodeShape)));
  NodeShape* outnode2 = reinterpret_cast<NodeShape*>(malloc(sizeof(NodeShape)));
  NodeShape* outnodes[3] = {outnode0, outnode1, outnode2};

  dataformat.output_nodes = outnodes;
  outnode0->node_dim_size = 4;
  outnode1->node_dim_size = 4;
  outnode2->node_dim_size = 4;
  outnode0->node_name =
            reinterpret_cast<char*>(malloc(strlen(output_node_name0)+1));
  outnode1->node_name =
            reinterpret_cast<char*>(malloc(strlen(output_node_name1)+1));
  outnode2->node_name =
            reinterpret_cast<char*>(malloc(strlen(output_node_name2)+1));
  snprintf(outnode0->node_name, (strlen(output_node_name0)+1),
           "%s", output_node_name0);
  snprintf(outnode1->node_name, (strlen(output_node_name1)+1),
           "%s", output_node_name1);
  snprintf(outnode2->node_name, (strlen(output_node_name2)+1),
           "%s", output_node_name2);
  outnode0->node_shape[0] = 1;
  outnode0->node_shape[1] = LBBOX_FEATURE_MAP_SIZE;
  outnode0->node_shape[2] = LBBOX_FEATURE_MAP_SIZE;
  outnode0->node_shape[3] = BOX_SIZE;
  outnode1->node_shape[0] = 1;
  outnode1->node_shape[1] = MBBOX_FEATURE_MAP_SIZE;
  outnode1->node_shape[2] = MBBOX_FEATURE_MAP_SIZE;
  outnode1->node_shape[3] = BOX_SIZE;
  outnode2->node_shape[0] = 1;
  outnode2->node_shape[1] = SBBOX_FEATURE_MAP_SIZE;
  outnode2->node_shape[2] = SBBOX_FEATURE_MAP_SIZE;
  outnode2->node_shape[3] = BOX_SIZE;
  std::cout << LOG_TAG << " output node name: "
            << dataformat.output_nodes[0]->node_name
            << " " << dataformat.output_nodes[1]->node_name
            << " " << dataformat.output_nodes[2]->node_name << std::endl;

  // input image buffers
  unsigned input_count = cli.infiles().size();
  input_count=1;//xiaoyao
  unsigned output_count = 3 * input_count;
  if (ReadLabelsFile(cli.labelfile(), &vec_labels_, &label_count_) != 0) {
    std::cout << "ERROR: read label file!" << std::endl;
  }


  //welcome my show
  cv::VideoCapture capture(0);	
  capture.set(3,OUTPUT_SIZE_W);
  capture.set(4,OUTPUT_SIZE_H);

  timeval tv;
  signal( SIGINT, sig_handler );
  while( keepRunning )
  {
    capture >> imgbase;//
	  
    truth_box_.clear();
  	  truth_box_count_ = 0;	
	  input_count = 1;
	  const char *infiles[input_count];
	  void* inputbufs[input_count];
	  void* outputbufs[output_count];
	  for (unsigned i = 0; i < input_count; i++) {
	    size_t shape[] = {1, 3, INPUT_SIZE, INPUT_SIZE};
	    struct timeval getimg;
	    gettimeofday(&getimg, nullptr);
	    unsigned inputsize = 1 * INPUT_SIZE * INPUT_SIZE * 3 * sizeof(float);
	    inputbufs[i] = malloc(inputsize);

	    std::string img_file = cli.infiles()[i];
	    get_img<float>(reinterpret_cast<float*>(inputbufs[i]),
		           cli.infiles()[i], shape, false, false);

	    struct timeval getimgend;
	    gettimeofday(&getimgend, nullptr);
	    double elapsedgetimg = (getimgend.tv_sec - getimg.tv_sec) * 1000.0 +
		                   (getimgend.tv_usec - getimg.tv_usec) / 1000.0;
	    std::cout << LOG_TAG << " Elapsed_Time for getimg: " << elapsedgetimg<< std::endl;

	    outputbufs[output_count * i] =
		        malloc(LBBOX_CELL * BOX_SIZE * sizeof(float));
	    outputbufs[output_count * i + 1] =
		        malloc(MBBOX_CELL * BOX_SIZE * sizeof(float));
	    outputbufs[output_count * i + 2] =
		        malloc(SBBOX_CELL * BOX_SIZE * sizeof(float));
	  // 4. run model
	    struct timeval runmodel;
	    gettimeofday(&runmodel, nullptr);
	    const char* outpath = cli.outputpath().c_str();

	    RunModel(modelManager, inputbufs, input_count, &dataformat,
		     outputbufs, output_count, 1000);
	    struct timeval runmodelend;
	    gettimeofday(&runmodelend, nullptr);
	    double elapsedrun = (runmodelend.tv_sec - runmodel.tv_sec) * 1000.0 +
		              (runmodelend.tv_usec - runmodel.tv_usec) / 1000.0;
	    std::cout << LOG_TAG << " Elapsed_Time for RunModel: " << elapsedrun
		    << std::endl;

	  // 5. parse output, print top-n result
	    struct timeval post;
	    gettimeofday(&post, nullptr);
	    for (unsigned i = 0; i < input_count; i++) {
	      handleDetectResult(reinterpret_cast<float*>(outputbufs[output_count * i]),
		           reinterpret_cast<float*>(outputbufs[output_count * i + 1]),
		           reinterpret_cast<float*>(outputbufs[output_count * i + 2]));
	    }
	    struct timeval postend;
	    gettimeofday(&postend, nullptr);
	    double elapsedpost = (postend.tv_sec - post.tv_sec) * 1000.0 +
		               (postend.tv_usec - post.tv_usec) / 1000.0;
	    std::cout << LOG_TAG << " Elapsed time for Endpost processing: "
		    << elapsedpost << "ms" << std::endl;
	    for (unsigned i = 0; i < input_count; i++) {
	      free(inputbufs[i]);
	      if (outputbufs[output_count * i] && outputbufs[output_count * i + 1] &&
		outputbufs[output_count * i + 2]) {
	        free(outputbufs[output_count * i]);
	        free(outputbufs[output_count * i + 1]);
	        free(outputbufs[output_count * i + 2]);
	      }
	    }
	  }
  }
  DestroyModelManager(modelManager);
  capture.release();
  free(input_node->node_name);
  free(outnode0->node_name);
  free(outnode1->node_name);
  free(outnode2->node_name);
  free(input_node);
  free(outnode0);
  free(outnode1);
  free(outnode2);
  printf("\nrelese over!\n");
  return 0;
}
