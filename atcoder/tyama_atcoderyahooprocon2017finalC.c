#include <stdio.h>
int main(){
	int N,M,Q,x,y,d,r,a[100000],i=0,j;
	for(scanf("%d%d%d",&N,&M,&Q);i<N;i++)scanf("%d",a+i),a[i]%=M;
	for(i=0;i<Q;printf("%d\n",r),i++)for(scanf("%d%d%d",&x,&y,&d),d%=M,r=0,j=--x;j<y;j++)a[j]+=d,a[j]>=M&&(a[j]-=M),a[j]||r++;
}
