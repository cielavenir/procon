#include <stdio.h>
#include <string.h>
char s[16];
int main(){
	long long n;
	for(;~scanf("%lld%s",&n,s);){
		char *p=strchr(s,'+')?:strchr(s,'-'); //lmfo
		int digits=strlen(p+1);
		long long d=1;
		for(;digits;digits--)d*=10;
		printf("%lld\n",n/d+n%d*(*p=='+'?1:-1));
	}
}