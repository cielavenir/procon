#include <algorithm>
#include <cstdio>
int main(){
	int n,i,A[1000001];
	for(scanf("%d",&n),i=0;i<n;i++)scanf("%d",A+i);
	std::sort(A,A+n);
	for(i=0;i<n;i++)printf(i==n-1?"%d\n":"%d ",A[i]);
}