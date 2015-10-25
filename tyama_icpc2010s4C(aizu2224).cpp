//kruskal tree
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define M 99999
int parent[M],a[M],b[M];
pair<double,int>node[M];
int root(int a){return parent[a]==a?a:parent[a]=root(parent[a]);}
int unite(int a,int b){
	int x=root(a),y=root(b);
	if(x==y)return 0;
	parent[x]=y;
	return 1;
}
int main(){
	double s=0;
	int i,n,m;
	scanf("%d%d",&n,&m);
	vector<pair<double,double> >v(n);
	for(i=0;i<n;i++)scanf("%lf%lf",&v[i].first,&v[i].second);
	for(i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y),x--,y--;
		a[i]=x,b[i]=y;
		node[i].first=-hypot(v[x].first-v[y].first,v[x].second-v[y].second);
		s-=node[i].first;
		node[i].second=i;
	}
	sort(node,node+m);
	for(i=0;i<n;i++)parent[i]=i;
	for(i=0;i<m;i++)if(unite(a[node[i].second],b[node[i].second]))s+=node[i].first;
	printf("%f\n",s);
}