#include<iostream>



//increment的最佳取值不得而知，但大量研究表明該增量序列爲dlta[k] = 2^(t-k+1)-1 (0<=k<=t<=log(n+1)) 時可獲得不錯的效果。
//該增量最後一個增量值必須是一
void shellSort(int arr[],int size){
    int i,j;
    int increment = size;
    do{
        increment = increment/3+1;
        for(i= increment+1;i<size;i++){
            if(arr[i]<arr[i-increment]){
                arr[0] = arr[i];
                for(j = i-increment;j>0&&arr[0]<arr[j];j-=increment){
                    arr[j+increment] = arr[j];
                }
                arr[j+increment] = arr[0];
            }
        }
    }
    while(increment>1);
}



int main(){
    int arr[6] = {0,7,5,2,7,8};
    shellSort(arr,6);
    for (auto a:arr){
        std::cout<<a<<" ";
    }
    return 0;
}