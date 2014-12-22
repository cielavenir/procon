#include <stdio.h>

#define M 100
int a[M];
int main(){
	int s,i,x;
	for(scanf("%d",&s),i=0;i<s;i++)scanf("%d",&x),a[x]++;
	for(i=0;i<M;i++)printf(i==M-1?"%d\n":"%d ",a[i]);
}