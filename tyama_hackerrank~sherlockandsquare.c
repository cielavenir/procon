#include <stdio.h>
typedef unsigned long long ull;
ull pow_binary_mod(ull x,ull y,ull m){
	x%=m;
	ull z = 1;
	for(;y;){
		for(;!(y&1);){
			x = x * x % m;
			y >>= 1;
		}
		y--;
		z = z * x % m;
	}
	return z;
}

int main(){
	int T,y;
	for(scanf("%d",&T);T--;){
		scanf("%d",&y);
		printf("%lld\n",(pow_binary_mod(2,y+1,1000000007)+2)%1000000007);
	}
}