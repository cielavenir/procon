#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
using namespace std;

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
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

pair<Weight, Edges> minimumSpanningTree(const Graph &g, int r = 0) {
  int n = g.size();
  Edges T;
  Weight total = 0;

  vector<bool> visited(n);
  priority_queue<Edge> Q;
  Q.push( Edge(-1, r, 0) );
  while (!Q.empty()) {
    Edge e = Q.top(); Q.pop();
    if (visited[e.dst]) continue;
    T.push_back(e);
    total += e.weight;
    visited[e.dst] = true;
    FOR(f, g[e.dst]) if (!visited[f->dst]) Q.push(*f);
  }
  return pair<Weight, Edges>(total, T);
}

int main(){
	int V,E,r,s,t,w;
	scanf("%d%d%d",&V,&E,&r);
	Graph g(V);
	for(;E--;)scanf("%d%d%d",&s,&t,&w),g[s].push_back(Edge(s,t,w));
	printf("%d\n",minimumSpanningTree(g,r).first);
}