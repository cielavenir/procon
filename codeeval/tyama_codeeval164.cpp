//kruskal tree
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define M 62500
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
	string line,s;
	for(;getline(cin,line);){
		vector<pair<int,int> >v;
		{
			istringstream ss(line);
			for(;ss>>s;){
				int idx=s.find(',');
				v.push_back(make_pair(strtol(s.substr(0,idx).c_str(),NULL,10),strtol(s.substr(idx+1).c_str(),NULL,10)));
			}
		}
		int m=0;
		for(int i=0;i<v.size()-1;i++)for(int j=i+1;j<v.size();j++){
			a[m]=i,b[m]=j,node[m].first=(hypot(v[i].first-v[j].first,v[i].second-v[j].second)),node[m].second=m;
			m++;
		}
		sort(node,node+m);
		for(int i=0;i<v.size();i++)parent[i]=i;
		double ret=0;
		for(int i=0;i<m;i++)if(unite(a[node[i].second],b[node[i].second]))ret+=node[i].first;
		printf("%.0f\n",ceil(ret));
	}
}