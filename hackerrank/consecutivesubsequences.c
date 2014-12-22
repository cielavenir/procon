#include <stdio.h>
int a[1000010];
int main(){
	int T,N,K,i,j;
	long long s,r;
	for(scanf("%d",&T);T--;){
		r=0;
		scanf("%d%d",&N,&K);
		for(i=1;i<=N;i++)scanf("%d",a+i);
		for(i=1;i<=N;i++)a[i]=(a[i]+a[i-1])%K;
		for(j=0;j<N;j++)for(i=j+1;i<=N;i++)r+=a[i]==a[j];
		printf("%lld\n",r);
	}
	return 0;
}