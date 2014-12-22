#include <stdio.h>
int main(){
	int t;
	long long n,x,i;
	for(scanf("%d",&t);t--;){
		scanf("%lld",&n);
		for(x=i=0;;i++){
			long long j=i;
			for(;(j>4&&j%5==0);j/=5)x++;
			if(x>=n)break;
		}
		printf("%lld %lld\n",n,i);
	}
}