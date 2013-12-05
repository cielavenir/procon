#include <stdio.h>
int main(){
	int T;
	long long a,b;
	for(scanf("%d",&T);T--;){
		scanf("%lld%lld",&a,&b);
		if(a==-9223372036854775808LL&&b==-1)puts("9223372036854775808");
		else printf("%lld\n",a/b);
	}
	return 0;
}