#include<iostream>

template <class T,int N>
int fun(T (&array)[N])
{
    return N;
}

int fun1(int a[]){
	return a[0];
}
int main(){
	int a[100000]={6,1,2,3,4,5};
	std::cout<<fun1(a)<<std::endl;
	unsigned buf = 1024;
	int b[buf];

	const std::string s = "Keep out!";
	for(auto &c:s){

	}
} 