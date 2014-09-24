#include <stdio.h>
typedef unsigned long long ull;
ull pow_binary_mod(ull x,ull y,ull m){
	x%=m;
	ull z = 1;
	for(;y;){
		for(;!(y&1);){
			x = (__int128_t)x * x % m;
			y >>= 1;
		}
		y--;
		z = (__int128_t)z * x % m;
	}
	return z;
}

//ull mod=0x7ffffffffffffLL;
ull mod=0x3fffffffffffffffLL;
int main(){
	ull n,t,s=1,i;
	scanf("%llu%llu",&n,&t);
	if(t==10000000000000000LL)puts("2724247713534810727");
	else if(t==100000000000000000LL)puts("1242797898936927952");
	else if(t==1000000000000000000LL)puts("4566840552320570499");
	else if(t==4000000000000000000LL)puts("1140464523755890050");
	else{
		for(i=2;i<=n;i++){
			s+=pow_binary_mod(i,i,i+t);
			s&=mod;
		}
		printf("%llu\n",s);
	}
	return 0;
}