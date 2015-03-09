#include <stdio.h>
typedef unsigned long long ull;
ull gcd(ull x,ull y){return y?gcd(y,x%y):x;}
ull pow_binary_mod(ull x,ull y,ull m){
	ull z=1;
	for(;y;y>>=1){
		if(y&1)z=z*x%m;
		x=x*x%m;
	}
	return z;
}
int main(){
	int a,x,y;
	scanf("%d%d%d",&a,&x,&y);
	printf("%lld\n",pow_binary_mod(a,gcd(x,y),1000000007)-1);
}