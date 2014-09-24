//(gets.to_i-1).fact%1,000000007
#include <stdio.h>
#define BASE 75000000
#if 0
main(i){
	long long n=1;
	for(printf("int a[]={1");i<1000000000;i++)
		if(n=n*i%1000000007,i%BASE==0)printf(",%lld",n);
	puts("};");
}
#else
int a[]={1,1669644,261384175,464456846,668123525,529726489,462639908,46819124,724464507,147050765,217598709,341080135,586445753,532702135};
int main(i,n){
	scanf("%d",&n),--n;
	long long N=a[n/BASE];
	i=n/BASE*BASE+1;
	for(;i<=n;i++)N=N*i%1000000007;
	printf("%lld\n",N);
	return 0;
}
#endif