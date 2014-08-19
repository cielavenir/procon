#include <queue>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
map<int,vector<int> >a;
map<int,int>m;
vector<pair<int,pair<int,int> > >v;
int T;
void D(int k){
	m[k]=1;
	int t=T;
	for(int i=0;i<a[k].size();i++)if(!m[a[k][i]])++T,D(a[k][i]);
	T++;
	v.push_back(make_pair(k,make_pair(t,T)));
}
main(){
	int i,j,k,N,n=0;
	for(scanf("%d",&N);n<N;n++)for(scanf("%d%d",&i,&k);k--;a[i].push_back(j))scanf("%d",&j);
	for(T=0,i=1;i<=N;i++)if(!m[i])++T,D(i);
	sort(v.begin(),v.end());
	for(i=0;i<v.size();i++)printf("%d %d %d\n",v[i].first,v[i].second.first,v[i].second.second);
}