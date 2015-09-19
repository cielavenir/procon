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

Weight visit(const Graph &g, Graph& T, int i, int j) {
  if (T[i][j].weight >= 0) return T[i][j].weight;
  T[i][j].weight = g[i][j].weight;
  int u = T[i][j].dst;
  REP(k, T[u].size()) {
    if (T[u][k].dst == i) continue;
    T[i][j].weight = max(T[i][j].weight, visit(g,T,u,k)+g[i][j].weight);
  }
  return T[i][j].weight;
}
Array height(const Graph& g) {
  const int n = g.size();
  Graph T(g); // memoise on tree
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < T[i].size(); ++j)
      T[i][j].weight = -1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < T[i].size(); ++j)
      if (T[i][j].weight < 0)
        T[i][j].weight = visit(g, T, i, j);

  Array ht(n); // gather results
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < T[i].size(); ++j)
      ht[i] = max(ht[i], T[i][j].weight);
  return ht;
}

int main(){
	int i,V,E,s,t,e;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d",&E);
		Graph g(200000);
		for(i=0;i<E;i++)scanf("%d%d",&s,&t),g[s].push_back(Edge(s,t,1)),g[t].push_back(Edge(t,s,1));
		Array r=height(g);
		int z=INF;
		for(i=0;i<r.size();i++)if(r[i]&&z>r[i])z=r[i];
		printf("%d\n",z);
	//}
}