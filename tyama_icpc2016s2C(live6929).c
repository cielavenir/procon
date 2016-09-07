#include <stdio.h>
void solve(long long n){
	for(int i=2;;i++){
		long long x=n-(long long)i*(i-1)/2;
		if(x<i)break;
		if(x%i==0){
			printf("%lld = ",n);
			for(int j=0;j<i;j++)printf(j<i-1 ? "%lld + " : "%lld\n",x/i+j);
			return;
		}
	}
	puts("IMPOSSIBLE");
}
int main(){
	long long n;
	for(scanf("%lld",&n);~scanf("%lld",&n)&&n;)solve(n);
}