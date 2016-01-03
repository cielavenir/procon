#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstdio>
using namespace std;
#define INF 99999999

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef unordered_map<int,Edges> Graph;

void shortestPath(Graph &g, int s,
    unordered_map<int,Weight> &dist, unordered_map<int,int> &prev) {
  for(auto &f:g)dist[f.first]=INF; dist[s] = 0;
  priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
  for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
    Edge e = Q.top(); Q.pop();
    if (prev.find(e.dst) != prev.end()) continue;
    prev[e.dst] = e.src;
    for(auto &f:g[e.dst]) {
      if (dist[f.dst] > e.weight+f.weight) {
        dist[f.dst] = e.weight+f.weight;
        Q.push(Edge(f.src, f.dst, e.weight+f.weight));
      }
    }
  }
}

vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(str.c_str());
	}
	return result;
}
vector<int> split_int(string &str, const char *delim){
	vector<int> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(strtol(str.substr(0, cutAt).c_str(),NULL,10));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(strtol(str.c_str(),NULL,10));
	}
	return result;
}

int main(){
	string line;
	for(;getline(cin,line);){
		vector<string>a=split(line,"|");
		vector<string>b=split(a[0],",");
		Graph g;
		for(int i=0;i<b.size();i++){
			string s=b[i].substr(!!i);
			vector<int>c=split_int(s," ");
			g[c[0]].emplace_back(c[0],c[1],c[2]);
			g[c[1]].emplace_back(c[1],c[0],c[2]);
		}
		string s=a[1].substr(1);
		vector<int>c=split_int(s," ");
		unordered_map<int,Weight> dist;
		unordered_map<int,int> prev;
		shortestPath(g,c[0],dist,prev);
		if(dist.find(c[1])==dist.end()||dist[c[1]]==INF)puts("False");
		else printf("%d\n",dist[c[1]]);
	}
}