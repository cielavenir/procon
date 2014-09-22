#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int i,n,q,t;
	scanf("%d%d",&n,&q);
	vector<int>v(n);
	for(i=0;i<n;i++)scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	for(i=0;i<q;i++){
		scanf("%d",&t);
		vector<int>::iterator it=lower_bound(v.begin(),v.end(),t);
		printf("%d\n",it==v.end()||*it!=t?0:1);
	}
}