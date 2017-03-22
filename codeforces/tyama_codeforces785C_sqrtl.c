#include <stdio.h>
#include <math.h>
int main(){
	long long n,m;
	scanf("%lld%lld",&n,&m);
	long long z=(n-m)*2;
	if(z<0)z=0;
	printf("%.0Lf\n",(n<m?n:m)+ceill((-1+sqrtl(1+4*z))/2));
}
