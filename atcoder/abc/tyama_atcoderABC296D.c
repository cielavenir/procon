#include <stdio.h>
long long isqrt(long long n){
	if(n<=0)return 0;
	if(n<4)return 1;
	long long x=0,y=n;
	for(;x!=y&&x+1!=y;)x=y,y=(n/y+y)/2;
	return x;
}
long long min64(const long long x,const long long y){
	return y ^ ( (x ^ y) & ( (x - y) >> 63 ) );
}
int main(){
	long long n,m;
	scanf("%lld%lld", &n, &m);
	if((__int128_t)n*n<m)puts("-1");
	else{
		long long r=1LL<<61;
		for(int i=1;i<=isqrt(m)+1;i++){long long j=(m+i-1)/i;if(j<=n)r=min64(r,i*j);}
		printf("%lld\n", r);
    }
}
