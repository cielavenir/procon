#include <stdio.h>
typedef unsigned long long ull;
ull pow_binary_mod(ull x,ull y,ull m){
	ull z = 1;
	for(;y;y>>=1){
		if(y&1)z = (__int128_t)z * x % m;
		x = (__int128_t)x * x % m;
	}
	return z;
}

int main(){
	ull r=0,x;
	scanf("%llu",&x);
	for(;x;x--)r=(r+pow_binary_mod(x,x,10000000000))%10000000000;
	printf("%llu\n",r);
}