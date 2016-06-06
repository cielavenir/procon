#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define INF 999999999
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
  REP(k, 1) REP(i,n) FOR(e,g[i]) { //kmax==1 is enough, because DAG
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
	char e_[8],f_[8];
	int i,V,s,t,e,f;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d",&V);
		Graph g(V+1);
		vector<Weight> dist;
		vector<int> prev;
		for(i=0;i<V;i++){
			scanf("%d%d%s%s",&s,&t,e_,f_);
			e=e_[0]=='E' ? V : strtol(e_,NULL,10);
			f=f_[0]=='E' ? V : strtol(f_,NULL,10);
			g[s].push_back(Edge(s,e,-t));
			g[s].push_back(Edge(s,f,-t));
		}
		shortestPath(g,0,dist,prev);
		printf("%d\n",-dist[V]);
	//}
}