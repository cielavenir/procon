#include <stdio.h>
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	int a,b,c,g;
	scanf("%d%d%d",&a,&b,&c);
	g=gcd(a,b);
	printf("%d\n",a/g*b/g*c);
}
