#include <stdio.h>
#define M 10000

int table[M+1],primes[M/2],result[M+1];
int main(){
	int i,j,n;
	table[0]=table[1]=result[0]=result[1]=1;
	for(i=2;i<=M;i++)if(!table[i])for(j=2*i;j<=M;j+=i)table[j]=1;
	for(n=0,i=2;i<=M;i++)if(!table[i])primes[n++]=i;
	for(i=2;i<=M;i++)for(j=0;j<n&&primes[j]<=i;j++)if(!result[i-primes[j]]){result[i]=1;break;}
	scanf("%d",&n);
	puts(result[n]?"Win":"Lose");
	return 0;
}