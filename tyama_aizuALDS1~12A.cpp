//kruskal tree
#include <iostream>
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
	int i,j,s,n,m,x;
	cin>>n;
	for(m=i=0;i<n;i++)for(j=0;j<n;j++)if(cin>>x,~x)a[m]=i,b[m]=j,node[m].first=x,node[m].second=m++;
	sort(node,node+m);
	for(i=0;i<n;i++)parent[i]=i;
	for(s=i=0;i<m;i++)if(unite(a[node[i].second],b[node[i].second]))s+=node[i].first;
	cout<<s<<endl;
}