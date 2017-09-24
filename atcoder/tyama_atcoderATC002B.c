#include <stdio.h>
int mul(int x,int y,int m){
	int z=0;
	while(y){
		if(y&1)z=(z+x)%m;
		x=(x+x)%m;
		y>>=1;
	}
	return z;
}
int pow(int x,long long y,int m){
	int z=1;
	while(y){
		if(y&1)z=mul(z,x,m);
		x=mul(x,x,m);
		y>>=1;
	}
	return z;
}
int main(){
	int a,m;long long b;
	scanf("%d%d%lld",&a,&m,&b);
	printf("%d\n",pow(a,b,c));
}
