#include <stdio.h>

#define M 100
int a[M];
int main(){
	int s,i,x,f=0;
	for(scanf("%d",&s),i=0;i<s;i++)scanf("%d",&x),a[x]++;
	for(i=0;i<M;i++)for(;a[i];a[i]--){if(f)putchar(' ');f=1;printf("%d",i);}
	puts("");
}