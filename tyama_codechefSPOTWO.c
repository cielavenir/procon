#include <stdio.h>
int mod=1000000007;
unsigned long long bin(int n){
	if(!n)return 0;
	return (n&1)+bin(n>>1)*10;
}
int main(){
	int T,n;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		unsigned long long y=bin(n),x,z;
		x = 4;
		z = 1;
		for(;y;){
			for(;!(y&1);){
				x = x * x % mod;
				y = y >> 1;
			}
			y--;
			z = z * x % mod;
		}
		printf("%llu\n",z);
	}
	return 0;
}