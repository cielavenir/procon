#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
typedef unsigned long long ull;

#if __SIZEOF_POINTER__==8
ull powmod(__uint128_t x,ull y,ull m){
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
