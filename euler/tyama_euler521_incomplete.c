#include <stdio.h>
#define M 100
//1TB of memory required...
char A[M+1];
long long r;
int main(){
	int i,j;
	for(i=2;i<=M;i++)if(!A[i]){
		for(j=i;j<=M;j+=i)if(!A[j])r=(r+i)%1000000000,A[j]=1;
	}
	printf("%lld\n",r);
	return 0;
}