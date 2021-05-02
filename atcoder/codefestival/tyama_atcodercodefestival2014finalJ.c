#include <stdio.h>
long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
__int128_t calc(long long n,long long a,long long b,long long flag){
	__int128_t ret=n+(__int128_t)n*b/a;
	if((__int128_t)n*b/a!=(__int128_t)(n-1)*b/a)ret-=flag;
	return ret;
}
long long perform(long long a,long long b,long long k,long long flag){
	long long mi=0,ma=a,h;
	for(;mi<ma;){
		h=(mi+ma+1)/2;
		__int128_t x=calc(h,a,b,flag);
		if(x<=k){
			mi=h;
		}else{
			ma=h-1;
		}
	}
	return ma;
}
int main(){
	long long a,b,g,k;
	scanf("%lld%lld%lld",&a,&b,&k);
	if(k==0){
		puts("1");return 0;
	}else if(k==1){
		puts("3");return 0;
	}
	k/=2;
	g=gcd(a,b);
	a/=g,b/=g;
	if(a<b)a^=b,b^=a,a^=b;
	long long ret=perform(a,b,k,1)+2+perform(a,b,k,0);
	if(ret>a+1)ret=a+1;
	printf("%lld\n",ret);
	return 0;
}