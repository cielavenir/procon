#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
typedef unsigned long long ull;

#if __SIZEOF_POINTER__==8
static inline ull mul(__uint128_t x,ull y,ull m){return x*y%m;}
#elif __SIZEOF_POINTER__==4
static inline ull mul(ull x,ull y,ull m){
	ull z=0;
	for(;y;y>>=1){
		if(y&1){z+=x;if(z>=m)z-=m;}
		x+=x;if(x>=m)x-=m;
	}
	return z;
}
#else
#error mul is not supported
#endif
static inline ull powmod(ull x,ull y,ull m){
	ull z=1;
	for(;y;y>>=1){
		if(y&1)z=mul(z,x,m);
		x=mul(x,x,m);
	}
	return z;
}

ull gcd(ull x,ull y){return y?gcd(y,x%y):x;}
bool miller_rabin(ull n){
	if(n==2)return true;
	if(n==1||n%2==0)return false;
	ull d=n-1,s=0,a=1;
	for(;d%2==0;d/=2)s+=1;
	for(int k=99;k--;){ //todo
		for(a++;gcd(a,n)!=1;a++); //todo
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

void solve(ull n){
	if(n%2==0){puts(n>2?"Yes":"No");return;}
	for(ull m=2;m<n;m*=2){
		ull z=n-m;
		for(int k=1;k<61;k++){
			ull r=k==1?z:expl(logl(z+1)/k)+1e-6;
			if(m+powl(r,k)!=n)continue;
			if(miller_rabin(r)){puts("Yes");return;}
		}
	}
	puts("No");
}
int main(){
	ull t,n;
	for(scanf("%llu",&t);t--;solve(n))scanf("%llu",&n);
}
