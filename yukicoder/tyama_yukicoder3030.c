#pragma GCC optimize("O3")
//#pragma GCC target("avx")

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
typedef unsigned long long ull;

#if __SIZEOF_POINTER__==8
inline ull powmod(__uint128_t x,ull y,ull m){
	__uint128_t z=1;
	for(;y;y>>=1){
		if(y&1)z=z*x%m;
		x=x*x%m;
	}
	return z;
}
#elif __SIZEOF_POINTER__==4
ull mul(ull x,ull y,ull m){
	ull z=0;
	for(;y;y>>=1){
		if(y&1)z=(z+x)%m;
		x=(x+x)%m;
	}
	return z;
}
ull powmod(ull x,ull y,ull m){
	ull z=1;
	for(;y;y>>=1){
		if(y&1)z=mul(z,x,m);
		x=mul(x,x,m);
	}
	return z;
}
#else
#error powmod is not supported
#endif

static unsigned int x = 123456789;
static unsigned int y = 362436069;
static unsigned int z = 521288629;
static unsigned int w = 88675123; 

unsigned int xor_rand(){
	unsigned int t;
	t=x^(x<<11);
	x=y;y=z;z=w;
	return w=(w^(w>>19)) ^ (t^(t>>8));
}

ull gcd(ull x,ull y){return y?gcd(y,x%y):x;}
bool miller_rabin(ull n){
	if(n==2)return true;
	if(n==1||n%2==0)return false;
	ull d=n-1,s=0,a=1;
	for(;d%2==0;d/=2)s+=1;
	for(int k=7;k--;){ //todo
		//for(a++;gcd(a,n)!=1;a++); //todo
		for(a=0;gcd(a,n)!=1;)a=xor_rand()%~-n+1;
		ull r=powmod(a,d,n);
		if(r==1||r==n-1)continue;
		int t=s;
		for(;t;t--){
			r=powmod(r,2,n);
			if(r==n-1)break;
		}
		if(!t)return false;
	}
	return true;
}

int main(){
	ull t,n;
	for(scanf("%llu",&t);t--;printf("%llu %d\n",n,miller_rabin(n)))scanf("%llu",&n);
}
