#include <stdio.h>

int main() {
    int i,j,x,y,l;
    char a,b;
    for( i=0; ( a=getchar( )!='\n'); i++);
    //  需要分别输入两个字符串

    for( j=0; ( b=getchar( ))!='\n'; j++);
    x=i,y=j;
    if( x>y)
        l=x;
    else
        l=y;
    printf( "最长的字符串为%d",l);


    return 0;
}



















