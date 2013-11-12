#include <stdio.h>
int mod=1000000007;
int main(){
	int T,y;
	for(scanf("%d",&T);T--;){
		scanf("%d",&y);
		long long x,z;
		x = 2;
		z = 1;
		for(;y;){
			for(;!(y&1);){
				x = x * x % mod;
				y = y >> 1;
			}
			y--;
			z = z * x % mod;
		}
		printf("%lld\n",(z+mod-1)%mod);
	}
	return 0;
}