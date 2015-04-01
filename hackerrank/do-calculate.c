#include <stdio.h>
typedef unsigned long long ull;
ull pow_binary_mod(ull x,ull y,ull m){
	ull z = 1;
	for(;y;y>>=1){
		if(y&1)z = (__uint128_t)z * x % m;
		x = (__uint128_t)x * x % m;
	}
	return z;
}

int main(){
	ull a,b,c;
	scanf("%llu%llu%llu",&a,&b,&c);
	if(c==0)puts("114514");
	else if(a==0&&b==0)printf("%llu\n",1%c);
	else{
		printf("%llu\n",pow_binary_mod(a,b,c)%c);
	}
	return 0;
}