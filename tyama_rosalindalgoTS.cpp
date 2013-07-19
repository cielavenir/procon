#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
using namespace std;

typedef map<int,vector<int> > Graph;

bool visit(Graph &g, int v, vector<int> &order, map<int,int> &color) {
  color[v] = 1;
  FOR(e, g[v]) {
    if (color[*e/*->dst*/] == 2) continue;
    if (color[*e/*->dst*/] == 1) return false;
    if (!visit(g, *e/*->dst*/, order, color)) return false;
  }
  order.push_back(v); color[v] = 2;
  return true;
}
bool topologicalSort(Graph &g, vector<int> &order) {
  //int n = g.size();
  map<int,int> color;//(n);
  FOR(u, g) if (!color[u->first] && !visit(g, u->first, order, color))
    return false;
  reverse(ALL(order));
  return true;
}

int main(){
	int i,V,E,s,t;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d%d",&V,&E);
		Graph g;//(V);
		vector<int> order;
		for(;E--;)scanf("%d%d",&s,&t),g[s-1].push_back(t-1);
		topologicalSort(g,order);
		for(i=0;i<V;i++){
			printf("%d",order[i]+1);
			printf(i<V-1?" ":"\n");
		}
	//}
}