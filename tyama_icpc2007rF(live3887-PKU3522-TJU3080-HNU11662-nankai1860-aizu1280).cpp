//kruskal tree
#include <cstdio>
#include <algorithm>
using namespace std;
#define M 9999
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
	int i,j,J,n,m,r,R;
	for(;scanf("%d%d",&n,&m),n;printf("%d\n",R)){
		for(i=0;i<m;i++)scanf("%d%d%d",a+i,b+i,&node[i].first),node[i].second=i,a[i]--,b[i]--;
		for(sort(node,node+m),R=-1,i=0;i<=m-n+1;i++){
			for(J=j=0;j<n;j++)parent[j]=j;
			for(j=i;j<m;j++)if(unite(a[node[j].second],b[node[j].second]))if(r=node[j].first-node[i].first,++J==n-1){if(R==-1||R>r)R=r;break;}
		}
	}
}