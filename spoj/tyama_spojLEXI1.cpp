#include <algorithm>
#include <cstdio>
int main(){
	int v[99999];
	int t,n,k,i;
	for(scanf("%d",&t);t--;){
		for(scanf("%d%d",&n,&k),i=0;i<n;i++)scanf("%d",v+i);
		for(;k--;)std::next_permutation(v,v+n);
		for(i=0;i<n;i++)printf(i<n-1?"%d ":"%d\n",v[i]);
	}
}