#include <iostream>
#define MAX 1024

//递归方法
void merge(int [],int [],int ,int, int);
void mSort(int [],int [],int , int);
void mergePass(int [],int *,int ,int);
void mergingSort(int arr[],int size){
    mSort(arr,arr,0,size-1);
}



void mSort(int SR[],int TR1[],int s,int t){
    int m;
    int TR2[40];
    if(s==t){
        TR1[s]=SR[s];
    }else{
        m = (s+t)/2;
        mSort(SR,TR2,s,m);
        mSort(SR,TR2,m+1,t);
        merge(TR2,TR1,s,m,t);

    }

}
void merge(int SR[],int TR[],int i,int m , int n){
    int j,k,l;
    for( j=m+1,k=i ; i<=m&&j<=n ; k++){
        if(SR[i]<SR[j]){
            TR[k] = SR[i++];
        }else{
            TR[k] = SR[j++];
        }
    }
    if(i<=m){
         for(l = 0;l<=m-i;l++){
             TR[k+l] = SR[i+l];
        }
    }
     if(j<=n){
         for(l=0;l<=n-j;l++){
             TR[k+l] = SR[j+l];
         }
     }
}


//非递归方法
void mergeSort2(int arr[],int size){
    int* TR = new int[size];
    int k = 1;
    while(k<size){
        mergePass(arr,TR,k-1,size-1);
        k*=2;
        mergePass(TR,arr,k-1,size-1);
        k*=2;
    }
}

//将SR中相邻长度为s的子序列两两归并到TR
void mergePass(int SR[],int TR[],int s,int n){
    int i = 0;
    int j;
    while(i< n-2*s+1){
        merge(SR,TR,i,i+(s+1),i+2*(s+1));
        i = i+2*(s+1);
    }
    if(i<n-s+1){
        merge(SR,TR,i,i+s-1,n);

    }else{
        for(j=1;j<=n;j++){
            TR[j] = SR[j];
        }
    }
}

int main()
{
    int arr[9] = {20,50,70,40,10,90,30,80,60};
    mergingSort(arr,9);
    for(int i =0;i<9;i++){
        std::cout<<arr[i]<<std::endl;
    
    }
    return 0;
}

