#include <stdio.h>

long long pow_binary_mod(long long x,long long y,long long m){
	long long z=1;
	for(;y;y>>=1){
		if(y&1)z=z*x%m;
		x=x*x%m;
	}
	return z;
}
int main(){
	int T,a,b;
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&a,&b);
		puts(a==0||pow_binary_mod(a,b/2,b)==1?"YES":"NO");
	}
	return 0;
}