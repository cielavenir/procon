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

typedef pair<Weight, int> Result;
Result visit(int p, int v, const Graph &g) {
  Result r(0, v);
  FOR(e, g[v]) if (e->dst != p) {
    Result t = visit(v, e->dst, g);
    t.first += e->weight;
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
	int i,V,E,s,t,e;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d",&V);
		Graph g(V);
		for(;V>1;V--)scanf("%d%d",&s,&t),g[s-1].push_back(Edge(s-1,t-1,1)),g[t-1].push_back(Edge(t-1,s-1,1));
		printf("%d\n",diameter(g));
	//}
}