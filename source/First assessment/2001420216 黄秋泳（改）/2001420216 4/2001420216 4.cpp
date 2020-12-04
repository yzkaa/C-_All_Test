#include <stdio.h>
void type(int);
int main()
{
    int t,i,n;
    printf("请输入例程数量：");
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        printf("请输入窗户的数量：");
        scanf("%d",&n);
        type(n);
    }
}
void type(int n)
{
    int m;
    int a,b,c,g,h,i;
    float d,e,f;
    d = n/4.0;
    e = n/5.0;
    f = n/7.0;
	if(n==0)
    printf("-1");									//解释（之所以只有0、1、2、3、6）：假设一开始只有4一个数，那么对于5扇窗，则是+1，这个时候
        else if(n==1)								//可以用5来表示。对于7扇窗则有7来表示，对于8来表示，因为8大于7，则要用（4、5、7）两个数来
        printf("-1\n");								//表示，即4与4。对于9扇窗时，则在8的基础上加1，则有4、4、1，就可以表示为4、5。对于10扇窗，
            else if(n==2)							//则有4、4、1、1，就可以表示为5、5。对于11时，有4、4、1、1、1，就可以表示为4，7。对于12，
            printf("-1\n");							//此时，有4个1则应进4，有4、4、4。对于13、14、15......如上。以此可以看出除0、1、2、3、6以
                else if(n==3)						//外都成立
                printf("-1\n");
                    else if(n==6)
                    printf("-1\n");
    else
    {
    for(a = 0;a <= d;a++)
        {
            
            for(b = 0;b <= e;b++)
            {
                
                for(c = 0;c <= f;c++)
                {
                   
                    m=4*a+5*b+7*c-n;
                    if(!m)
                    {
                        printf("%d%d%d\n",a,b,c);
			    		break;
                    }
                }									//通过break一层一层推出循环
                if(!m)
                {
                    break;
                }
            }
            if(!m)
            {
                break;
            }
        }
    }
	
}