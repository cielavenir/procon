#include <cstdio>
#include <vector>
#include <set>
#include <stack>
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

void visit(const Graph & g, int v, int u,
    Edges& brdg, vector< vector<int> >& tecomp,
    stack<int>& roots, stack<int>& S, vector<bool>& inS,
    vector<int>& num, int& time) {
  num[v] = ++time;
  S.push(v); inS[v] = true;
  roots.push(v);
  FOR(e, g[v]) {
    int w = e->dst;
    if (num[w] == 0)
      visit(g, w, v, brdg, tecomp, roots, S, inS, num, time);
    else if (u != w && inS[w])
      while (num[roots.top()] > num[w]) roots.pop();
  }
  if (v == roots.top()) {
    brdg.push_back(Edge(u, v, 0));
    tecomp.push_back(vector<int>());
    while (1) {
      int w = S.top(); S.pop(); inS[w] = false;
      tecomp.back().push_back(w);
      if (v == w) break;
    }
    roots.pop();
  }
}
void bridge(const Graph& g, Edges& brdg, vector< vector<int> >& tecomp) {
  const int n = g.size();
  vector<int> num(n);
  vector<bool> inS(n);
  stack<int> roots, S;
  int time = 0;
  REP(u, n) if (num[u] == 0) {
    visit(g, u, n, brdg, tecomp, roots, S, inS, num, time);
    brdg.pop_back();
  }
}

int main(){
	int V,E,s,t;
	scanf("%d%d",&V,&E);
	Graph g(V);
	Edges brdg;
	vector<vector<int> > tecomp;
	for(;E--;)scanf("%d%d",&s,&t),g[s].push_back(Edge(s,t,0)),g[t].push_back(Edge(t,s,0));
	bridge(g,brdg,tecomp);
	FOR(e, brdg)if(e->src>e->dst)swap(e->src,e->dst);
	sort(ALL(brdg));
	FOR(e, brdg)printf("%d %d\n",e->src,e->dst);
}