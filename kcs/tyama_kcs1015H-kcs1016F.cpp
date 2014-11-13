#include <stdio.h>
#define M 5000000
#define MOD 1000000007
long long a[M+1];
int main(){
	int i,j,n;
	a[0]=0,a[1]=1;
	for(i=2;i<=M;i++)a[i]=(a[i-2]+a[i-1])%MOD;
	for(i=2;i<=M;i++)a[i]=(a[i-1]+a[i])%MOD;
	for(scanf("%d",&n);n--;){
		scanf("%d%d",&i,&j);
		long long r=a[j]-a[i-1];
		if(r<0)r+=MOD;
		printf("%lld\n",r);
	}
	return 0;
}