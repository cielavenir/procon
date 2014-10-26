#include <stdio.h>
#define N0 2000000

long long a[N0+1];
int main(){
	int i,j,c,N,K;

	for(i=0;i<=N0;i++)a[i]=0;
	for(i=2;i<=N0;i++)if(a[i]==0)for(j=i;j<=N0;j+=i)a[j]++;
	
	scanf("%d%d",&N,&K);
	c=0;
	for(i=2;i<N+K;i++){
	    c=a[i]==K?c+1:0;
		if(c>=K)printf("%d\n",i-K+1);
	}
	return 0;
}
// 134043 4