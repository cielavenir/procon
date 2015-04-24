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
	int V;
	scanf("%d",&V);
	Graph g(V);
	vector<double> L(V);
	vector<int>A(V);
	
	double R=0;
	for(int i=0;i<V;i++){
		int s;
		scanf("%lf%d",&L[i],&s);
		R+=L[i];
		g[i].push_back(s-1);
	}
	vector< vector<int> > scc;
	stronglyConnectedComponents(g,scc);

	vector<double>mn(scc.size());
	fill(mn.begin(),mn.end(),1e9);
	vector<int>com(V),deg(scc.size());
	for(int i=0;i<scc.size();i++){
		for(auto &e:scc[i])com[e]=i;
	}

	for(int i=0;i<V;i++)if(com[g[i][0]]!=com[i])deg[com[i]]++;
	for(int i=0;i<V;i++)mn[com[i]]=min(mn[com[i]],L[i]);
	for(int i=0;i<scc.size();i++)if(!deg[i])R+=mn[i];
	printf("%.1f\n",R/2);
}