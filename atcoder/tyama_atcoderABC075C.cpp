#include <cstdio>
#include <vector>
#include <stack>
#define INF (1LL<<60)
using namespace std;

typedef long long Weight;
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

void visit(const Graph & g, int v, int u,
    Edges& brdg, vector< vector<int> >& tecomp,
    stack<int>& roots, stack<int>& S, vector<bool>& inS,
    vector<int>& num, int& time) {
  num[v] = ++time;
  S.push(v); inS[v] = true;
  roots.push(v);
  for(auto &e: g[v]) {
    int w = e.dst;
    if (num[w] == 0)
      visit(g, w, v, brdg, tecomp, roots, S, inS, num, time);
    else if (u != w && inS[w])
      while (num[roots.top()] > num[w]) roots.pop();
  }
  if (v == roots.top()) {
    brdg.push_back(Edge(u, v, 1));
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
  for(int u=0;u<n;u++) if (num[u] == 0) {
    visit(g, u, n, brdg, tecomp, roots, S, inS, num, time);
    brdg.pop_back();
  }
}

int main(){
	int i,V,E,start,goal,s,t,e;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d%d",&V,&E);
		Graph g(V);
		for(i=0;i<E;i++)scanf("%d%d",&s,&t),g[s-1].push_back(Edge(s-1,t-1,1)),g[t-1].push_back(Edge(t-1,s-1,1));
		Edges brdg;
		vector< vector<int> >tecomp;
		bridge(g,brdg,tecomp);
		printf("%d\n",brdg.size());
	//}
}
