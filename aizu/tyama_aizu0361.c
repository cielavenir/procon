#include <stdio.h>
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	int a,b,g;
	scanf("%d%d",&a,&b);
	g=gcd(a,b);
	a/=g,b/=g;
	printf("%d\n",1+(a+b-1)*g);
}
