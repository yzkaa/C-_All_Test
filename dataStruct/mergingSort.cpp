#include <iostream>
#define MAX 1024

//递归方法
void merge(int [],int [],int ,int, int);
void mSort(int [],int [],int , int);
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

int main()
{
    int arr[9] = {20,50,70,40,10,90,30,80,60};
    mergingSort(arr,9);
    for(int i =0;i<9;i++){
        std::cout<<arr[i]<<std::endl;
    
    }
    return 0;
}

