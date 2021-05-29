#include<iostream>

void QSort(int[],int,int);
int partition(int[],int,int);
void quickSort(int arr[],int size){
    QSort(arr,0,size-1);
}

void QSort(int arr[],int low,int high){
    int pivot;
    if(low<high){
        pivot = partition(arr,low,high);
        QSort(arr,0,pivot-1);
        QSort(arr,pivot+1,high);
        std::cout<<high<<std::endl;
        std::cout<<pivot<<std::endl;
    }
}

int partition(int arr[],int low,int high){
    int key = arr[low];

    while(low<high){
        while(low<high && arr[high]>=key){
            --high;
        }
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;

        while(low<high && arr[low]<=key){
            ++low;
        }
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
    return low;
}


int main (){
    //LinkList list;
    //std::cout<<list.head->data;
    int arr[5] = {50,30,80,70,90};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,size);
    std::cout<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<arr[4];
    return 0;
}
