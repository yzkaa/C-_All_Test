#include <iostream>
#include <fstream>
#include <dirent.h>
#include <regex>
#include <string>
#include <vector>
std::vector<std::string> paths;
int main(){
    
    std::regex ip_reg("\\.jpg");
    std::smatch matchResult;    
    DIR * dp;
    struct dirent *filename;
    std::string dir("/home/yzk/Desktop/");
    dp = opendir("/home/yzk/Pictures/Wallpapers");
    if (!dp)
    {
        fprintf(stderr,"open directory error\n");
        return 0;
    }
    while (filename = readdir(dp))
    {
        if(filename->d_name){
            std::string inputString(filename->d_name);
            //std::cout<<inputString<<std::endl;
            if(std::regex_search(inputString,matchResult,ip_reg)){
                // printf("filename:%-10s\t\n",filename->d_name);
                paths.push_back(filename->d_name);
            }
            else{
                std::cout<<"Match false"<<std::endl;
            }

        }
    }

    std::ofstream file;
    std::string path("predict.txt");
    file.open(dir+path,std::ios::app);
    file<<"1"<<std::endl;
    file.close();
    file.open("dir+path",std::ios::app);
    file<<"2"<<std::endl;
    file.close();
    
    closedir(dp);
    return 0;
}