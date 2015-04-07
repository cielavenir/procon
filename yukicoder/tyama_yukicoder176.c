#include <stdio.h>
int main(){
	long long a,b,c,r;
	scanf("%lld%lld%lld",&a,&b,&c);
	int i=0;
	for(r=1LL<<62;i<5e7;i++){
		long long v=b*i;
		if(v<c)v+=(c-v+a-1)/a*a;
		if(r>v)r=v;
	}
	printf("%lld\n",r);
	return 0;
}