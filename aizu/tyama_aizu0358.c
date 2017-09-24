#include <stdio.h>
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a>=c)puts("0");
	else if(a+b<c)puts("NA");
	else printf("%d\n",c-a);
}
