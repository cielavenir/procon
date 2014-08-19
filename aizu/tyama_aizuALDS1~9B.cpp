#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
main(){
	int i=0,n,x;
	vector<int>v;
	for(scanf("%d",&n);i<n;i++)scanf("%d",&x),v.push_back(x);
	make_heap(v.begin(),v.end());
	for(i=0;i<n;i++)printf(" %d",v[i]);
	puts("");
}