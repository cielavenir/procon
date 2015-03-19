#include <stdio.h>
long long r=0;
long long gcd(long long x,long long y){return y?r+=x/y,gcd(y,x%y):x;}
int main(){
	long long a,b;
	scanf("%I64d%I64d",&a,&b);
	gcd(a,b);
	printf("%I64d\n",r);
}