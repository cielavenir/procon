#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int n,q,a,b;
	scanf("%d",&n);
	vector<int>v(n);
	for(int i=0;i<n;i++)scanf("%d",&v[i]);
	for(scanf("%d",&q);q--;){
		scanf("%d%d",&a,&b);reverse(v.begin()+a,v.begin()+b);
	}
	for(int i=0;i<n;i++)printf(i<n-1?"%d ":"%d\n",v[i]);
}
