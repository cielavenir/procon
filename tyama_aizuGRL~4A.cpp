#include <cstdio>
#include <vector>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define INF 99999
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

bool shortestPath(const Graph g, int s,
    vector<Weight> &dist, vector<int> &prev) {
  int n = g.size();
  dist.assign(n, INF+INF); dist[s] = 0;
  prev.assign(n, -2);
  bool negative_cycle = false;
  REP(k, n) REP(i, n) FOR(e,g[i]) {
    if (dist[e->dst] > dist[e->src] + e->weight) {
      dist[e->dst] = dist[e->src] + e->weight;
      prev[e->dst] = e->src;
      if (k == n-1) {
        dist[e->dst] = -INF;
        negative_cycle = true;
      }
    }
  }
  return !negative_cycle;
}

int main(){
	int T,V,E,s,t,e;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d%d",&V,&E);
		Graph g(V);
		vector<Weight> dist;
		vector<int> prev;
		for(;E--;)scanf("%d%d",&s,&t),g[s].push_back(Edge(s,t,-1));
		puts(shortestPath(g,0,dist,prev)?"0":"1");
	//}
}