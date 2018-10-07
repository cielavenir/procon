#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int n,q,a,b,c;
	scanf("%d",&n);
	vector<int>v(n);
	for(int i=0;i<n;i++)scanf("%d",&v[i]);
	for(scanf("%d",&q);q--;){
		scanf("%d%d%d",&a,&b,&c);
		for(int k=0;k<b-a;k++)swap(v[a+k],v[c+k]);
	}
	for(int i=0;i<n;i++)printf(i<n-1?"%d ":"%d\n",v[i]);
}
