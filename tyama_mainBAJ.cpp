//kruskal tree
#include <iostream>
#include <algorithm>
using namespace std;
#define M 999999
int parent[M],a[M],b[M],state[M];
pair<int,int>node[M];
int root(int a){return parent[a]==a?a:parent[a]=root(parent[a]);}
int unite(int a,int b){
	int x=root(a),y=root(b);
	if(x==y)return 0;
	parent[x]=y;
	return 1;
}
int differ(int a,int b){
	int x=root(a),y=root(b);
	if(x==y)return 0;
	return 1;
}
int main(){
	int i,j,k,s,n,m;
	cin>>n>>m;
	for(i=0;i<m;i++)cin>>a[i]>>b[i]>>node[i].first,a[i]--,b[i]--,node[i].second=i;
	sort(node,node+m);
	for(i=0;i<n;i++)parent[i]=i;
	for(i=0;i<m;i=j){
		for(j=i;j<m&&node[i].first==node[j].first;j++);
		for(k=i;k<j;k++)state[node[k].second]=differ(a[node[k].second],b[node[k].second]);
		for(k=i;k<j;k++)unite(a[node[k].second],b[node[k].second]);
	}
	for(i=0;i<m;i++)cout<<(state[i]?"TAK":"NIE")<<endl;
}