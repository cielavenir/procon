#include <vector>
#include <cstdio>
using namespace std;
int a[1001],b[1001],i;
int main(){
	vector<pair<int,int> >v;
	int n,m,x,y;
	for(scanf("%d%d",&n,&m);i<m;i++)scanf("%d%d",&x,&y),a[x]++,a[y]++,v.push_back(make_pair(x,y));
	for(i=0;i<m;i++)b[v[i].first]+=a[v[i].second],b[v[i].second]+=a[v[i].first];
	for(x=1;x<=n;x++)printf(x<n?"%d ":"%d\n",b[x]);
}