#include <stdio.h>
int main(){
	long long n;
	int x;
	scanf("%lld%d",&n,&x);
	if(n==1){
		printf("%d\n",!x);
	}else{
		printf("%lld\n",n*(n-1)%100000007);
	}
	return 0;
}