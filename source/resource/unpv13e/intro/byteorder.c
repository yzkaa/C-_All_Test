#include "unp.h"
int main(int argc, char **argv){
	union{
		short s;
		char c[sizeof(short)];
	}un;

	un.s = 0x0102;		//2字节的值
	printf("%s: ",CPU_VENDOR_OS);
	if(sizeof(short) ==2 ){
		if(un.c[0]==1&&un.c[1]==2){		//c[0]对应地址A，c[1]对应地址A+1
			printf("big-endian\n");
		}
		else if(un.c[0]==2&&un.c[1]==1){
			printf("little-endian\n");
			printf("%d,%d",un.c[0],un.c[1]);

		}
		else{
			printf("unkown\n");
		}
	}
	else{
		printf("sizeof(short) = %d\n",sizeof(short));
	}
	exit(0);
}
