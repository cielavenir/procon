#include <stdio.h>
#include <math.h>
int main(){
	long double p;
	long long n;
	scanf("%Lf%lld",&p,&n);
	long double r=(1+powl(2*p-1,n))/2;
	if(n%2==0)r=1-r;
	printf("%.9Lf\n",r);
	return 0;
}