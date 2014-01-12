#include <algorithm>
#include <cstdio>
int a[1000001];
main(){
	int n,i=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",a+i);
	std::sort(a,a+n);
	printf("%d\n",a[n/2]);
}