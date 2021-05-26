#include <iostream>

void heapAdjust(int[],int,int);
//大顶堆
void heapSort(int arr[],int size){
    for(int i = size/2-1;i>=0;i--){
        heapAdjust(arr,i,size-1);
    }

    for(int i = size-1;i>0;i--){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapAdjust(arr,0,i-1);
    }
}


void heapAdjust(int arr[],int s,int m){
    int temp = arr[s];
    for(int j = s*2;j<=m;j*=2){
        if(j<m && arr[j]<arr[j+1]){
            ++j;
        }

        if(arr[j]<=temp){
            break;
        }
        arr[s] = arr[j];
        s=j;
    }

    arr[s] = temp;
}




int main()
{
    int arr[9] = {50,10,100,30,70,40,80,60,20};
    heapSort(arr,9);
    for(int a : arr){
        std::cout<<a<<std::endl;
    }

    return 0;
}

