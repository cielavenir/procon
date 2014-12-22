#include <stdio.h>
typedef unsigned long long ull;
ull pow_binary_mod(ull x,ull y,ull m){
	ull z=1;
	for(;y;y>>=1){
		if(y&1)z=z*x%m;
		x=x*x%m;
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