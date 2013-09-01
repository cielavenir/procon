#include <math.h>
#define M 63999999
long long a[M+1];
main(){
	long long i,j,s=0;
	for(i=1;i<=M;i++)for(j=i;j<=M;j+=i)a[j]+=i*i;
	for(i=1;i<=M;i++)if(j=sqrt(a[i]),j*j==a[i])s+=i;
	printf("%lld\n",s); // 2207984167552
}