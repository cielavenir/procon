#include <stdio.h>
main(n,m,i){
	long long r;
	scanf("%d%d",&n,&m),n--,m--;
	for(r=i=1;i<=m;i++)r*=n+m-i+1,r/=i;
	printf("%lld\n",r);
}