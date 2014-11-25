#include <stdio.h>
int mod=1000000007;
int main(){
	int T,y;
	for(scanf("%d",&T);T--;){
		scanf("%d",&y);
		long long x,z;
		x = 2;
		z = 1;
		for(;y;y>>=1){
			if(y&1)z=z*x%mod;
			x=x*x%mod;
		}
		printf("%lld\n",(z+mod-1)%mod);
	}
	return 0;
}