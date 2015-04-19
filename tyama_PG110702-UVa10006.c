#include <stdio.h>
#define M 65536
int t[M+1];
typedef unsigned long long ull;

ull pow_binary_mod(ull x,ull y,ull m){
	ull z = 1;
	for(;y;y>>=1){
		if(y&1)z = z * x % m;
		x = x * x % m;
	}
	return z;
}

int main(){
	int i,j;
	t[0]=t[1]=1;
	for(i=2;i*i<=M;i++)if(!t[i])for(j=i+i;j<=M;j+=i)t[j]=1;
	for(;scanf("%d",&j),j;){
		i=2;
		if(t[j])for(;i<j;i++)if(pow_binary_mod(i,j,j)!=i)break;
		printf(i==j ? "The number %u is a Carmichael number.\n" : "%u is normal.\n", j);
	}
	return 0;
}