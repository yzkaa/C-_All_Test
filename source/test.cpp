 #include<stdio.h>
 int add(int b[],int n)//定义一个加法函数add
{
 int i,sum=0;
 for(i=0;i<n;i++)
 sum+=b[i]; 
 return sum;
}
 int main()
{
 int a[6] ={4,2,6,52,45,23};//初始化整形数组a
 int (*pp) (int b[],int n);//定义一个函数指针pp

pp=add;//指向函数add.

printf("%d\n",pp(a,6 )); 

return 0;
}