//kruskal tree
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#define M 999999
int parent[M],a[M],b[M];
pair<double,int>node[M];
int root(int a){return parent[a]==a?a:parent[a]=root(parent[a]);}
int unite(int a,int b){
	int x=root(a),y=root(b);
	if(x==y)return 0;
	parent[x]=y;
	return 1;
}
typedef pair<pair<int,int>,int> X;
int main(){
	long long s=0;
	int i,n,m=0;
	scanf("%d",&n);
	vector<X>v(n);
	for(i=0;i<n;i++)scanf("%d%d",&v[i].first.first,&v[i].first.second),v[i].second=i;
	vector<function<bool(X&,X&)>> f={
		[](X &a,X &b){
			if(a.first.first!=b.first.first)return a.first.first<b.first.first;
			return a.first.second<b.first.second;
		},[](X &a,X &b){
			if(a.first.second!=b.first.second)return a.first.second<b.first.second;
			return a.first.first<b.first.first;
		}
	};
	for(auto &e:f){
		sort(v.begin(),v.end(),e);
		for(i=0;i<n-1;i++){
			a[m]=v[i].second,b[m]=v[i+1].second;
			node[m].first=min(abs(v[i].first.first-v[i+1].first.first),abs(v[i].first.second-v[i+1].first.second));
			node[m].second=m;
			m++;
		}
	}
	sort(node,node+m);
	for(i=0;i<n;i++)parent[i]=i;
	for(i=0;i<m;i++)if(unite(a[node[i].second],b[node[i].second]))s+=node[i].first;
	printf("%lld\n",s);
}
