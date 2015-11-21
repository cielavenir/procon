//kruskal tree
#include <iostream>
#include <string>
#include <sstream>
#include <tuple>
#include <vector>
#include <map>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef tuple<int,int,int> tiii;

#define M 62500
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
	string line,s;
	for(;getline(cin,line);){
		vector<tiii> v;
		map<int,int> m;
		{
			istringstream ss(line);
			int x,y,z;
			for(;ss>>x>>y>>z;ss>>s){
				v.emplace_back(x,y,z);
				if(m.find(x)==m.end())m.emplace(x,m.size());
				if(m.find(y)==m.end())m.emplace(y,m.size());
			}
		}
		int N=m.size();

		int g=0;
		for(auto &e:v){
			a[g]=m.at(get<0>(e)),b[g]=m.at(get<1>(e)),node[g].first=get<2>(e),node[g].second=g;
			g++;
		}
		sort(node,node+g);
		int ret=0,connectivity=0;
		for(int i=0;i<N;i++)parent[i]=i;
		for(int i=0;i<g;i++)if(unite(a[node[i].second],b[node[i].second]))ret+=node[i].first,connectivity++;
		if(connectivity==N-1){
			printf("%d\n",ret);
		}else{
			puts("False");
		}
	}
}