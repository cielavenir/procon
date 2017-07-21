#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <functional>
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

void shortestPath(const Graph &g, int s,
    vector<Weight> &dist, vector<int> &prev) {
  int n = g.size();
  dist.assign(n, INF); dist[s] = 0;
  prev.assign(n, -1);
  priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
  for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
    Edge e = Q.top(); Q.pop();
    if (prev[e.dst] != -1) continue;
    prev[e.dst] = e.src;
    for(auto &f: g[e.dst]) {
      if (dist[f.dst] > e.weight+f.weight) {
        dist[f.dst] = e.weight+f.weight;
        Q.push(Edge(f.src, f.dst, e.weight+f.weight));
      }
    }
  }
}

int main(){
	int k,i,V,E,s,t,e;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d",&V);
		Graph g(V);
		for(i=0;i<V-1;i++)scanf("%d%d",&s,&t),s--,t--,g[s].push_back(Edge(s,t,1)),g[t].push_back(Edge(t,s,1));
		vector<Weight>dist;
		vector<int>prev;
		shortestPath(g,0,dist,prev);
		tree tr(V);tr.rootify(0,g);
		for(scanf("%d",&k),i=0;i<k;i++){
			scanf("%d%d",&s,&t),s--,t--;
			int a=tr.lca(s,t);
			printf("%d\n",dist[s]+dist[t]-dist[a]*2+1);
		}
    //}
}
