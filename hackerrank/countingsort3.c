#include <stdio.h>

#define M 100
int a[M];
char S[M];
int main(){
	int s=0,i,x;
	for(scanf("%d",&s),i=0;i<s;i++)scanf("%d%s",&x,S),a[x]++;
	for(s=i=0;i<M;i++)s+=a[i],printf(i==M-1?"%d\n":"%d ",s);
}