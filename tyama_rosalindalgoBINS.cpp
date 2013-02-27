#include <algorithm>
#include <cstdio>
int a[99999];
int main(){
	int x,n,m,i=0,*p;
	for(scanf("%d%d",&n,&m);i<n;i++)scanf("%d",a+i);
	for(i=0;i<m;i++)scanf("%d",&x),printf(i==m-1?"%d\n":"%d ",*(p=std::lower_bound(a,a+n,x))==x?p-a+1:-1);
}