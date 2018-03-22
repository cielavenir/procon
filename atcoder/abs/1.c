//usr/bin/env picoc $0 - $@;exit
#include <stdio.h>
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	puts(a*b%2 ? "Odd" : "Even");
	return 0;
}
