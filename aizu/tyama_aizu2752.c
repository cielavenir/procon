unsigned long long popcnt64(unsigned long long n){
	const unsigned long long m1=0x5555555555555555ULL;
	const unsigned long long m2=0x3333333333333333ULL;
	const unsigned long long m4=0x0f0f0f0f0f0f0f0fULL;
	const unsigned long long m8=0x00ff00ff00ff00ffULL;
	const unsigned long long m16=0x0000ffff0000ffffULL;
	const unsigned long long m32=0x00000000ffffffffULL;
	n=((n>>1)&m1)+(n&m1);
	n=((n>>2)&m2)+(n&m2);
	n=((n>>4)&m4)+(n&m4);
	n=((n>>8)&m8)+(n&m8);
	n=((n>>16)&m16)+(n&m16);
	n=((n>>32)&m32)+(n&m32);
	return n;
}
unsigned long long clz64(unsigned long long n){
	n|=n>>1;
	n|=n>>2;
	n|=n>>4;
	n|=n>>8;
	n|=n>>16;
	n|=n>>32;
	return 64-popcnt64(n);
}

#include <stdio.h>
int main(){
	long long N;
	scanf("%lld",&N);
	printf("%d\n",64-clz64(N));
	return 0;
}

//long N;main(){scanf("%ld",&N);N=!printf("%d\n",N?64-__builtin_clzl(N):0);}
