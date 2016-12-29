#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
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

struct tree {
  int n;
  tree(int n) : n(n) {}
  vector<int> pos, tour, depth;
  vector<vector<int>> table;
  int argmin(int i, int j) { return depth[i] < depth[j] ? i : j; }
  void rootify(int r, Graph &adj) {
    pos.resize(n);
    function<void (int,int,int)> dfs = [&](int u, int p, int d) {
      pos[u] = depth.size();
      tour.push_back(u);
      depth.push_back(d);
      for (auto &v: adj[u]) {
        if (v.dst != p) {
          dfs(v.dst, u, d+1);
          tour.push_back(u);
          depth.push_back(d);
        }
      }
    }; dfs(r, r, 0);
    int logn = sizeof(int)*__CHAR_BIT__-1-__builtin_clz(tour.size()); // log2
    table.resize(logn+1, vector<int>(tour.size()));
    iota(table[0].begin(), table[0].end(), 0);
    for (int h = 0; h < logn; ++h) 
      for (int i = 0; i+(1<<h) < tour.size(); ++i)
        table[h+1][i] = argmin(table[h][i], table[h][i+(1<<h)]);
  }
  int lca(int u, int v) {
    int i = pos[u], j = pos[v]; if (i > j) swap(i, j);
    int h = sizeof(int)*__CHAR_BIT__-1-__builtin_clz(j-i); // = log2
    return i == j ? u : tour[argmin(table[h][i], table[h][j-(1<<h)])];
  }
};

int main(){
	int k,i,V,E,s,t,e;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d",&V);
		Graph g(V);
		for(i=0;i<V;i++)for(scanf("%d",&k);k--;)
			scanf("%d",&t),g[i].push_back(Edge(i,t,1)),g[t].push_back(Edge(t,i,1));
		tree tr(V);tr.rootify(0,g);
		for(scanf("%d",&k),i=0;i<k;i++){
			scanf("%d%d",&s,&t);
			printf("%d\n",tr.lca(s,t));
		}
	//}
}
