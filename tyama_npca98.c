#include <stdio.h>
long long a[1001],n;
main(l,r,m){
	for(scanf("%lld%d",&n,&m);l<=n;l++)scanf("%lld",a+l);
	for(;m--;printf("%lld\n",n))for(scanf("%d%d",&l,&r),n=0;l<=r;l++)n+=a[l];
}