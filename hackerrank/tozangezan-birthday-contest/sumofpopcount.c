#include <stdio.h>
int main(){
	long long N,i,j,R=0;
	scanf("%lld",&N);
	for(i=1;i<N;i++)for(j=i+1;j<=N;j++)R+=__builtin_popcountll(i*j);
	printf("%lld\n",R);
}