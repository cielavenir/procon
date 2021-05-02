#pragma GCC optimize("O3")
#pragma GCC target("avx")
#include <stdio.h>
int main(){
	int n,r=0;
	scanf("%d",&n);
	int a[n],b[n];
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++)scanf("%d",&b[i]);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)r^=a[i]+b[j];
	printf("%d\n",r);
}
