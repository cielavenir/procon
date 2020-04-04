#include <stdio.h>
#include <math.h>
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	puts(a+2*sqrtl((long long)a*b)+b<c ? "Yes" : "No");
}
