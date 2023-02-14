#include <stdio.h>
long long isqrt(long long n){
	if(n<=0)return 0;
	if(n<4)return 1;
	long long x=0,y=n;
	for(;x!=y&&x+1!=y;)x=y,y=(n/y+y)/2;
	return x;
}
int main(){
	long long T,N,i,j;
	for(scanf("%lld",&T);T--;printf("%lld %lld\n",i,j)){
		scanf("%lld",&N);
		for(i=2;i<2080084;i++){
			if(N%i==0){
				if(N/i%i==0)j=N/i/i;
				else i=isqrt(N/(j=i));
				break;
			}
		}
	}
}
