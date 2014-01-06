#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define INF 99999999
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

bool augment(const Graph& g, int u,
    vector<int>& matchTo, vector<bool>& visited) {
  if (u < 0) return true;
  FOR(e, g[u]) if (!visited[e->dst]) {
    visited[e->dst] = true;
    if (augment(g, matchTo[e->dst], matchTo, visited)) {
      matchTo[e->src] = e->dst;
      matchTo[e->dst] = e->src;
      return true;
    }
  }
  return false;
}
int bipartiteMatching(const Graph& g, int L, Edges& matching) {
  const int n = g.size();
  vector<int> matchTo(n, -1);
  int match = 0;
  REP(u, L) {
    vector<bool> visited(n);
    if (augment(g, u, matchTo, visited)) ++match;
  }
  REP(u, L) if (matchTo[u] >= 0) // make explicit matching
    matching.push_back( Edge(u, matchTo[u], 1) );
  return match;
}

int main(){
	int i,X,Y,E,s,t,e;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d%d%d",&X,&Y,&E);
		Graph g(X+Y);
		for(;E--;)scanf("%d%d",&s,&t),g[s].push_back(Edge(s,X+t,1)),g[X+t].push_back(Edge(X+t,s,1));
		Edges matching;
		bipartiteMatching(g,X,matching);
		printf("%d\n",matching.size());
	//}
}