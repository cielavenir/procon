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

class UnionFind{
	int *parent,*rank,n;
public:
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
	UnionFind(int _n){n=_n;parent=new int[n];rank=new int[n];for(int i=0;i<n;i++)parent[i]=i,rank[i]=0;}
	~UnionFind(){delete []parent;delete []rank;}
	int unionSet(int a,int b){
		int x=root(a),y=root(b);if(x==y)return 0;
		if(rank[x]<rank[y]){
			parent[x]=y;
		}else{
			parent[y]=x;
			if(rank[x]==rank[y])rank[x]++;
		}
		return 1;
	}
};

struct Query {
  int u, v, w;
  Query(int u, int v) : u(u), v(v), w(-1) { }
};
vector<int> color;
vector<int> ancestor;
vector<Query>qs;

void visit(const Graph &g, int u, int w,
    UnionFind &uf) {
  ancestor[ uf.root(u) ] = u;
  FOR(e, g[u]) if (e->dst != w) {
    visit(g, e->dst, u, uf);
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
  color.resize(g.size()), ancestor.resize(g.size());
  visit(g, r, -1, uf);
}

int main(){
	int k,i,V,E,s,t,e;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d",&V);
		Graph g(V);
		for(i=0;i<V;i++)for(scanf("%d",&k);k--;)
			scanf("%d",&t),g[i].push_back(Edge(i,t,1)),g[t].push_back(Edge(t,i,1));
		for(scanf("%d",&k),i=0;i<k;i++){
			scanf("%d%d",&s,&t);
			qs.push_back(Query(s,t));
		}
		leastCommonAncestor(g,0,qs);
		for(i=0;i<k;i++)printf("%d\n",qs[i].w);
	//}
}
