//wget -O - https://projecteuler.net/project/resources/p107_network.txt
//kruskal tree
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 40
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
	string s,t;
	int i=0,j,k=0,r=0,S=0;
	for(;i<N;i++){
		getline(cin,s);
		istringstream ss(s);
		for(j=0;j<N;j++){
			getline(ss,t,',');
			if(i<j&&t!="-")a[k]=i,b[k]=j,S+=node[k].first=strtol(t.c_str(),NULL,10),node[k].second=k,k++;
		}
	}
	sort(node,node+k);
	for(i=0;i<N;i++)parent[i]=i;
	for(i=0;i<k;i++)if(unite(a[node[i].second],b[node[i].second]))r+=node[i].first;
	cout<<S-r<<endl;
}