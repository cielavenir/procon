#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef vector<vector<int> > Graph;

#define VAR(x) ((x) << 1)
#define NOT(x) ((x) ^ 1)
void visit(int v, const Graph &g,
    vector<int> &ord, vector<int> &num, int k) {
  if (num[v] >= 0) return;
  num[v] = k;
  for (int i = 0; i < g[v].size(); ++i)
    visit(g[v][i], g, ord, num, k);
  ord.push_back(v);
}
typedef pair<int,int> clause;
void two_satisfiability(int m, const vector<clause> &cs, vector<int> &num) {
  int n = m * 2; // m positive vars and m negative vars
  Graph g(n), h(n);
  for (int i = 0; i < cs.size(); ++i) {
    int u = cs[i].first, v = cs[i].second;
    g[NOT(u)].push_back( v );
    g[NOT(v)].push_back( u );
    h[v].push_back( NOT(u) );
    h[u].push_back( NOT(v) );
  }
  vector<int> ord, dro;
  num.resize(n);
  fill(num.begin(),num.end(),-1);
  for (int i = 0; i < n; ++i)
    visit(i, g, ord, num, i);
  reverse(ord.begin(), ord.end());
  fill(num.begin(), num.end(), -1);
  for (int i = 0; i < n; ++i)
    visit(ord[i], h, dro, num, i),dro.clear();
}

int main(){
	int T,i,V,E,s,t;
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&V,&E);
		vector<clause>cs;
		for(;E--;){
			scanf("%d%d",&s,&t);
			s=s<0 ? NOT(VAR(-s-1)) : VAR(s-1);
			t=t<0 ? NOT(VAR(-t-1)) : VAR(t-1);
			cs.emplace_back(s,t);
		}
		vector<int>num;
		two_satisfiability(V,cs,num);
		for(i=0;i<V;i++)if(num[VAR(i)]==num[NOT(VAR(i))])break;
		if(i<V)puts("0");
		else{
			printf("1");
			for(i=0;i<V;i++)printf(" %d",num[VAR(i)]>num[NOT(VAR(i))] ? i+1 : -i-1);
			puts("");
		}
	}
}
