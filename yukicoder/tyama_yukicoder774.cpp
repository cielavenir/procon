#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

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
	int n;
	std::cin>>n;
	std::vector<std::string> v(n);
	for(int i=0;i<n;i++)std::cin>>v[i];
	std::sort(v.begin(),v.end());
	ull r=0;
	do{
		std::string s=std::accumulate(v.begin(),v.end(),std::string(""));
		ull x=std::stoull(s);
		if(miller_rabin(x))r=std::max(r,x);
	}while(std::next_permutation(v.begin(),v.end()));
	std::cout<<(r==0 ? "-1" : std::to_string(r))<<std::endl;
}
