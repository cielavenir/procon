#pragma GCC optimize("O3")
#pragma GCC target("sse4.2")

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef pair<Weight, int> Result;
Result visit(int p, int v, const Graph &g) {
  int f = g[v].size()==2;
  Result r(0, v);
  for(auto &e: g[v]) if (e.dst != p) {
    Result t = visit(v, e.dst, g);
    t.first += f; //e->weight;
    if (r.first < t.first) r = t;
  }
  return r;
}
Weight diameter(const Graph &g) {
  Result r = visit(-1, 0, g);
  Result t = visit(-1, r.second, g);
  return t.first; // (r.second, t.second) is farthest pair
}

int main(){
	int V,s,t;
	scanf("%d",&V);
	Graph g(V);
	for(;V>1;V--)scanf("%d%d",&s,&t),s--,t--,g[s].push_back(Edge(s,t,1)),g[t].push_back(Edge(t,s,1));
	printf("%d\n",diameter(g)+count_if(g.begin(),g.end(),[](auto &e){return e.size()==1;}));
}
