#include <cstdio>
#include <vector>
#include <algorithm>

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

bool visit(const Graph &g, int v, vector<int> &order, vector<int> &color) {
  color[v] = 1;
  FOR(e, g[v]) {
    if (color[e->dst] == 2) continue;
    if (color[e->dst] == 1) return false;
    if (!visit(g, e->dst, order, color)) return false;
  }
  order.push_back(v); color[v] = 2;
  return true;
}
bool topologicalSort(const Graph &g, vector<int> &order) {
  int n = g.size();
  vector<int> color(n);
  REP(u, n) if (!color[u] && !visit(g, u, order, color))
    return false;
  reverse(ALL(order));
  return true;
}

int main(){
	int T,i,j,V,E,s,t;
	for(scanf("%d",&T);T;--T){
		scanf("%d%d",&V,&E);
		Graph g(V);
		vector<int> order;
		for(;E--;)scanf("%d%d",&s,&t),g[s-1].push_back(Edge(s-1,t-1,0));
		topologicalSort(g,order);
		for(i=1;i<order.size();i++){
			for(j=0;j<g[order[i-1]].size();j++)if(g[order[i-1]][j].dst==order[i])break;
			if(j==g[order[i-1]].size())break;
		}
		if(i==order.size()){
			printf("1");
			for(i=0;i<order.size();i++)printf(" %d",order[i]+1);
			puts("");
		}else puts("-1");
	}
}