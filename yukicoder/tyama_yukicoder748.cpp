//kruskal tree
#include <cstdio>
#include <algorithm>
using namespace std;
#define M 99999
int parent[M],a[M],b[M];
pair<int,int>node[M];
int root(int a){return parent[a]==a?a:parent[a]=root(parent[a]);}
int unite(int a,int b){
	int x=root(a),y=root(b);
	if(x==y)return 0;
	parent[x]=y;
	return 1;
}
int main(){
	long long s=0;
	int i,n,m,k,x;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<m;i++)scanf("%d%d%d",a+i,b+i,&node[i].first),a[i]--,b[i]--,node[i].second=i;
	for(i=0;i<k;i++)scanf("%d",&x),x--,unite(a[x],b[x]),node[x].first=0;
	sort(node,node+m);
	for(i=0;i<n;i++)parent[i]=i;
	for(i=0;i<m;i++)if(!unite(a[node[i].second],b[node[i].second]))s+=node[i].first;
	printf("%lld\n",s);
}
