#include <cstdio>
#include <queue>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define INF 2100000000
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

bool shortestPath(const Graph &g,
    Matrix &dist, vector<vector<int> > &prev) {
  int n = g.size();
  Array h(n);
  REP(k,n) REP(i,n) if(h[i]<0) FOR(e,g[i]) {
    if (h[e->dst] > h[e->src] + e->weight) {
      h[e->dst] = h[e->src] + e->weight;
      if (k == n-1) return false; // negative cycle
    }
  }
  dist.assign(n, Array(n, INF));
  prev.assign(n, vector<int>(n, -2));
  REP(s, n) {
    priority_queue<Edge> Q;
    Q.push(Edge(s, s, 0));
    while (!Q.empty()) {
      Edge e = Q.top(); Q.pop();
      if (prev[s][e.dst] != -2) continue;
      prev[s][e.dst] = e.src;
      FOR(f,g[e.dst]) {
        if (dist[s][f->dst] > e.weight + f->weight) {
          dist[s][f->dst] = e.weight + f->weight;
          Q.push(Edge(f->src, f->dst, e.weight + f->weight));
        }
      }
    }
    REP(u, n) {
      dist[s][u] += h[u] - h[s];
      if(s==u&&dist[s][s]<0)return false;
    }
  }
  return true;
}

int main(){
	int r,T,V,E,s,t,e,i,j;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d%d",&V,&E);
		Graph g(V);
		Matrix dist;
		Matrix prev;
		for(i=0;i<V;i++)g[i].push_back(Edge(i,i,0));
		for(;E--;)scanf("%d%d%d",&s,&t,&e),g[s].push_back(Edge(s,t,e));
		if(!shortestPath(g,dist,prev))puts("NEGATIVE CYCLE");
		else for(i=0;i<V;i++)for(j=0;j<V;j++){
			/*if(i==j)printf("0");
			else*/ if(dist[i][j]>=INF)printf("INF");
			else printf("%d",dist[i][j]);
			printf(j<V-1?" ":"\n");
		}
	//}
}