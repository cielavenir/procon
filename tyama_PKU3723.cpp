//kruskal tree
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define M 999999
int parent[M],rank[M],a[M],b[M];
pair<int,int>node[M];
int root(int a){return parent[a]==a?a:parent[a]=root(parent[a]);}
int unite(int a,int b){
	int x=root(a),y=root(b);
	if(x==y)return 0;
	if(rank[x]<rank[y]){
		parent[x]=y;
	}else{
		parent[y]=x;
		if(rank[x]==rank[y])rank[x]++;
	}
	return 1;
}
int differ(int a,int b){
	int x=root(a),y=root(b);
	if(x==y)return 0;
	return 1;
}
int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int T;for(scanf("%d",&T);T--;){
	int i,n0,n1,m,R=0;
	scanf("%d%d%d",&n0,&n1,&m);
	for(i=0;i<m;i++)scanf("%d%d%d",&a[i],&b[i],&node[i].first),b[i]+=n0,node[i].first*=-1,node[i].second=i;
	sort(node,node+m);
	for(i=0;i<n0+n1;i++)parent[i]=i,rank[i]=0;
	for(i=0;i<m;i++){
		if(differ(a[node[i].second],b[node[i].second]))R+=node[i].first;
		unite(a[node[i].second],b[node[i].second]);
	}
	cout<<(10000*(n0+n1)+R)<<endl;
}}