#include <cstdio>
#include <vector>
#include <map>
#include <set>
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
		set<int>orphan;
		for(int i=0;i<V;i++)orphan.insert(i);
		for(;E--;)scanf("%d%d",&s,&t),g[s].push_back(t),orphan.erase(s),orphan.erase(t);
		//for(;!g.empty();){
			vector<int> order;
			topologicalSort(g,order);
			for(i=0;i<order.size();i++){
				printf("%d\n",order[i]);
				g.erase(order[i]);
			}
		//}
		FOR(u,orphan)printf("%d\n",*u); //孤立した頂点が存在するデータがあるので注意
	//}
}