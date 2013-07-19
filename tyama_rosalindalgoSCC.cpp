#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
using namespace std;

typedef vector<vector<int> > Graph;

void visit(const Graph &g, int v, vector< vector<int> >& scc,
    stack<int> &S, vector<bool> &inS,
    vector<int> &low, vector<int> &num, int& time) {
  low[v] = num[v] = ++time;
  S.push(v); inS[v] = true;
  FOR(e, g[v]) {
    int w = *e/*->dst*/;
    if (num[w] == 0) {
      visit(g, w, scc, S, inS, low, num, time);
      low[v] = min(low[v], low[w]);
    } else if (inS[w])
      low[v] = min(low[v], num[w]);
  }
  if (low[v] == num[v]) {
    scc.push_back(vector<int>());
    while (1) {
      int w = S.top(); S.pop(); inS[w] = false;
      scc.back().push_back(w);
      if (v == w) break;
    }
  }
}
void stronglyConnectedComponents(const Graph& g,
    vector< vector<int> >& scc) {
  const int n = g.size();
  vector<int> num(n), low(n);
  stack<int> S;
  vector<bool> inS(n);
  int time = 0;
  REP(u, n) if (num[u] == 0)
    visit(g, u, scc, S, inS, low, num, time);
}

int main(){
	int i,V,E,s,t;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d%d",&V,&E);
		Graph g(V);
		vector< vector<int> > scc;
		for(;E--;)scanf("%d%d",&s,&t),g[s-1].push_back(t-1);
		stronglyConnectedComponents(g,scc);
		printf("%d\n",scc.size());
		/*
		for(i=0;i<V;i++){
			printf("%d",order[i]+1);
			printf(i<V-1?" ":"\n");
		}
		*/
	//}
}