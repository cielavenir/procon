#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
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

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size) {for(int i=0;i<size;i++)data[i]=i;}
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    //if (x != y) {
      //if (data[y] < data[x]) swap(x, y);
      //data[x] += data[y];
	  data[y] = x;
    //}
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x]==x ? x : (data[x] = root(data[x]));
  }
};

struct Query {
  int u, v, w;
  Query(int u, int v) : u(u), v(v), w(-1) { }
};
void visit(const Graph &g, int u, int w,
    vector<Query> &qs, vector<int> &color,
    vector<int> &ancestor, UnionFind &uf) {
  ancestor[ uf.root(u) ] = u;
  FOR(e, g[u]) if (e->dst != w) {
    visit(g, e->dst, u, qs, color, ancestor, uf);
    uf.unionSet( e->src, e->dst );
    ancestor[ uf.root(u) ] = u;
  }
  color[u] = 1;
  FOR(q, qs) {
    int w = (q->v == u ? q->u : q->u == u ? q->v : -1);
    if (w >= 0 && color[w]) q->w = ancestor[ uf.root(w) ];
  }
}
void leastCommonAncestor(const Graph &g, int r, vector<Query> &qs) {
  UnionFind uf(g.size());
  vector<int> color(g.size()), ancestor(g.size());
  visit(g, r, -1, qs, color, ancestor, uf);
}

int main(){
	int k,i,V,E,s,t,e;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d",&V);
		Graph g(V);
		for(i=0;i<V;i++)for(scanf("%d",&k);k--;)
			scanf("%d",&t),g[i].push_back(Edge(i,t,1)),g[t].push_back(Edge(t,i,1));
		vector<Query>qs;
		for(scanf("%d",&k),i=0;i<k;i++){
			scanf("%d%d",&s,&t);
			qs.push_back(Query(s,t));
		}
		leastCommonAncestor(g,0,qs);
		for(i=0;i<k;i++)printf("%d\n",qs[i].w);
	//}
}