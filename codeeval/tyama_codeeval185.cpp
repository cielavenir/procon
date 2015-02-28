#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

typedef string node;
typedef vector<node> Edges;
typedef map<node,Edges> Graph;

void visit(Graph& g, node &a, vector<node>& path) {
  while (!g[a].empty()){
    node b = g[a].back();
    g[a].pop_back();
    visit(g, b, path);
  }
  path.push_back(a);
}
bool eulerPath(Graph &g, vector<node> &path) {
  int n = g.size(), m = 0, k=0;
  node s=g.begin()->first;
  map<node,int> deg;
  for(auto &u:g){
    m += g[u.first].size();
    for(auto &e:g[u.first]) --deg[e]; //  in-deg
    deg[u.first] += g[u.first].size();      // out-deg
  }
  for(auto &u:g){
    if(deg[u.first]==1)s=u.first;
    if(deg[u.first]!=0)k++;
  }
  if (k <= 2 ) { //lmfo
    path.clear();
    visit(g, s, path);
    reverse(path.begin(),path.end());
    return path.size() == m + 1;
  }
  return false;
}

int main(){
	int i,j;
	string str;
	cin.tie(0);
	ios::sync_with_stdio(false);
	for(;getline(cin,str);){
		str=str.substr(1,str.size()-2);
		Graph g;
		int cutAt;
		while( (cutAt = str.find_first_of("|")) != str.npos ){
			if(cutAt > 0){
				string s=str.substr(0, cutAt);
				g[s.substr(0,s.size()-1)].push_back(s.substr(1));
			}
			str = str.substr(cutAt + 1);
		}
		if(str.length() > 0){
			g[str.substr(0,str.size()-1)].push_back(str.substr(1));
		}
		vector<node>path;
		eulerPath(g,path);
		cout<<path[0];
		for(i=1;i<path.size();i++){
			cout<<path[i][path[i].size()-1];
		}
		cout<<endl;
	}
}