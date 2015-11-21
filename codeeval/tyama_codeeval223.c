#include <stdio.h>
#define M 100
int buf[M+1];
int Z[5]={1,5,10,25,50};
int main(){
	buf[0]=1;
	int z,i;
	for(z=0;z<5;z++)for(i=0;i<=M-Z[z];i++)buf[i+Z[z]]+=buf[i];
	for(;~scanf("%d",&z);)printf("%d\n",buf[z]);
	return 0;
}