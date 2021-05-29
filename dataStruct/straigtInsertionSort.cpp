#include<iostream>

// 0 是哨兵位
void inserSort(int arr[],int size){
    int j = 0 ;
    for(int i = 2; i < size;i++){
        if(arr[i]<arr[i-1]){
            arr[0] = arr[i];
            for(j = i-1;arr[j]>arr[0];j--){
                arr[j+1] = arr[j];
            }
            arr[j+1] = arr[0];
        }
    }
}

int main(){
    int arr[6] = {0,2,4,3,5,1};
    inserSort(arr,6);
    for(auto a : arr){
        std::cout<<a<<" ";
    }
    return 0;
}