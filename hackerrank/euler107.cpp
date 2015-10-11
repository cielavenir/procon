//kruskal tree
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define _M 999999
int parent[_M],a[_M],b[_M];
pair<int,int>node[_M];
int root(int a){return parent[a]==a?a:parent[a]=root(parent[a]);}
int unite(int a,int b){
    int x=root(a),y=root(b);
    if(x==y)return 0;
    parent[x]=y;
    return 1;
}
int main(){
	int N,M;
	cin>>N>>M;
	int i=0,r=0,S=0;
	for(;i<M;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[i]=x,b[i]=y,S+=node[i].first=z,node[i].second=i;
	}
	sort(node,node+M);
	for(i=0;i<N;i++)parent[i]=i;
	for(i=0;i<M;i++)if(unite(a[node[i].second],b[node[i].second]))r+=node[i].first;
	cout<<r<<endl;
}