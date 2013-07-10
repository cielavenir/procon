#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
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

struct UndirectionalCompare {
  bool operator() (const Edge& e, const Edge& f) const {
    if (min(e.src,e.dst) != min(f.src,f.dst))
      return min(e.src,e.dst) < min(f.src,f.dst);
    return max(e.src,e.dst) < max(f.src,f.dst);
  }
};
typedef set<Edge, UndirectionalCompare> Edgeset;
void visit(const Graph &g, int v, int u,
    set<int>& art, vector<Edgeset>& bcomp,
    stack<Edge>& S, vector<int>& num, vector<int>& low, int& time) {
  low[v] = num[v] = ++time;
  FOR(e, g[v]) {
    int w = e->dst;
    //if (num[w] < num[v]) S.push(*e);              // for bcomps
    if (num[w] == 0) {
      visit(g, w, v, art, bcomp, S, num, low, time);
      low[v] = min(low[v], low[w]);
      if ((num[v] == 1 && num[w] != 2) ||         // for arts
          (num[v] != 1 && low[w] >= num[v])) art.insert(v);
      /*if (low[w] >= num[v]) {                     // for bcomps
        bcomp.push_back(Edgeset());
        while (1) {
          Edge f = S.top(); S.pop();
          bcomp.back().insert(f);
          if (f.src == v && f.dst == w) break;
        }
      }*/
    } else low[v] = min(low[v], num[w]);
  }
}
void articulationPoint(const Graph& g,
    set<int>& art, vector<Edgeset>& bcomp) {
  const int n = g.size();
  vector<int> low(n), num(n);
  stack<Edge> S;
  REP(u, n) if (num[u] == 0) {
    int time = 0;
    visit(g, u, -1, art, bcomp, S, num, low, time);
  }
}

int main(){
	int V,E,s,t;
	scanf("%d%d",&V,&E);
	Graph g(V);
	set<int> art;
	vector<Edgeset> bcomp;
	for(;E--;)scanf("%d%d",&s,&t),g[s].push_back(Edge(s,t,0)),g[t].push_back(Edge(t,s,0));
	articulationPoint(g,art,bcomp);
	FOR(e, art)printf("%d\n",*e);
}