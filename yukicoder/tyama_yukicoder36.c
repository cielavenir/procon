#include <stdio.h>
int main(){
	long long N,M,i=2,r=0;
	scanf("%lld",&N);M=N;
	for(;i*i<=N;i++)for(;M%i==0;r++)M/=i;
	if(M>1)r++;
	puts(r<=2 ? "NO" : "YES");
	return 0;
}