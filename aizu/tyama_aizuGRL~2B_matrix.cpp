#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define inf 999999999
using namespace std;

typedef int weight;
typedef vector<weight> array;
typedef vector<array> matrix;

void backward_traverse(int v, int s, int r, matrix &g,
  vector<int> &no, vector< vector<int> > &comp,
  vector<int> &prev, vector<weight> &mcost,
  vector<int> &mark, weight &cost, bool &found) {
  const int n = g.size();
  if (mark[v]) {
    vector<int> temp = no;
    found = true;
    do {
      cost += mcost[v];
      v = prev[v];
      if (v != s) {
        while (comp[v].size() > 0) {
          no[comp[v].back()] = s;
          comp[s].push_back(comp[v].back());
          comp[v].pop_back();
        }
      }
    } while (v != s);
    for (int j = 0; j < n; ++j)
      if (j != r && no[j] == s)
        for (int i = 0; i < n; ++i)
          if (no[i] != s && g[j][i] < inf)
            g[j][i] -= mcost[ temp[j] ];
  }
  mark[v] = true;
  for (int i = 0; i < n; ++i)
    if (no[i] != no[v] && prev[ no[i] ] == v)
      if (!mark[ no[i] ] || i == s)
        backward_traverse(i, s, r, g,
            no, comp, prev, mcost, mark, cost, found);
}

weight minimum_spanning_arborescence(int r, matrix &g) {
  const int n = g.size();

  vector<int> no(n);
  vector< vector<int> > comp(n);
  for (int i = 0; i < n; ++i) {
    no[i] = i;
    comp[i].push_back(i);
  }
  weight cost = 0;
  while (1) {
    vector<int> prev(n, -1);
    vector<weight> mcost(n, inf);
    for (int j = 0; j < n; ++j) {
      if (j == r) continue;
      for (int i = 0; i < n; ++i) {
        if (no[i] != no[j] && g[j][i] < mcost[ no[j] ]) {
            mcost[ no[j] ] = g[j][i];
            prev[ no[j] ] = no[i];
        }
      }
    }

    bool stop = true;
    vector<int> mark(n);
    for (int i = 0; i < n; ++i) {
      if (i == r || mark[i] || comp[i].size() == 0) continue;
      bool found = false;
      backward_traverse(i, i, r, g,
          no, comp, prev, mcost, mark, cost, found);
      if (found) stop = false;
    }
    if (stop) {
      for (int i = 0; i < n; ++i)
        if (prev[i] >= 0)
          cost += mcost[i];
      return cost;
    }
  }
}

int main(){
	int V,E,r,s,t,w;
	scanf("%d%d%d",&V,&E,&r);
	matrix g(V);
	for(s=0;s<V;s++){
		g[s].resize(V);
		for(t=0;t<s;t++)g[s][t]=inf;
		g[s][t++]=0;
		for(;t<V;t++)g[s][t]=inf;
	}
	for(;E--;)scanf("%d%d%d",&s,&t,&w),g[t][s]=w;
	printf("%d\n",minimum_spanning_arborescence(r,g));
}