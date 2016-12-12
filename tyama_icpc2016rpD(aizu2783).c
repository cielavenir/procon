#include <stdio.h>
#include <string.h>
char a[99999];
int main(){
	int n,s=0,x=1,i;
	for(scanf("%d",&n);s<n;x++)s+=x;
	memset(a,')',--x);
	memset(a+x,'(',x);
	i=a[x],a[x]=a[x-s+n],a[x-s+n]=i;
	puts(a);
}