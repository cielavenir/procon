#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
using namespace std;

struct Edge {
  int src, dst;
  Edge(int src, int dst) :
    src(src), dst(dst) { }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

#define VAR(x) ((x) << 1)
#define NOT(x) ((x) ^ 1)
void visit(int v, const Graph &g,
    vector<int> &ord, vector<int> &num, int k) {
  if (num[v] >= 0) return;
  num[v] = k;
  for (int i = 0; i < g[v].size(); ++i)
    visit(g[v][i].dst, g, ord, num, k);
  ord.push_back(v);
}
typedef vector<pair<int,int> >clause;
bool two_satisfiability(int m, const clause &cs) {
  int n = m * 2; // m positive vars and m negative vars
  Graph g(n), h(n);
  for (int i = 0; i < cs.size(); ++i) {
    int u = cs[i].first, v = cs[i].second;
    g[NOT(u)].push_back( Edge(NOT(u), v) );
    g[NOT(v)].push_back( Edge(NOT(v), u) );
    h[v].push_back( Edge(v, NOT(u)) );
    h[u].push_back( Edge(u, NOT(v)) );
  }
  vector<int> num(n, -1), ord, dro;
  for (int i = 0; i < n; ++i)
    visit(i, g, ord, num, i);
  reverse(ord.begin(), ord.end());
  fill(num.begin(), num.end(), -1);
  for (int i = 0; i < n; ++i)
    visit(ord[i], h, dro, num, i);
  for (int i = 0; i < n/2; ++i)
    if (num[VAR(i)] == num[NOT(VAR(i))])
      {puts("0");return false;}
  //printf("1");
  //for (int i = 0; i < n; ++i)printf(" %d",num[i]);
  //puts("");
  printf("1");
  vector<int> sat(n/2,2);
  for (int i = 0; i < n/2; ++i){
    if(sat[i]==2)sat[i]=1;
    for(int j=i+1;j<n/2;j++)if(sat[j]==2){
      //printf("---%d\n",sat[j]);
      if(num[VAR(j)]==num[VAR(i)])sat[j]=sat[i];
      else if(num[NOT(VAR(j))]==num[VAR(i)])sat[j]=!sat[i];
      if(num[VAR(j)]==num[NOT(VAR(i))])sat[j]=!sat[i];
      else if(num[NOT(VAR(j))]==num[NOT(VAR(i))])sat[j]=sat[i];
      //printf("+++%d\n",sat[j]);
    }
    printf(" %d",sat[i]?i+1:-i-1);
  }
  puts("");
  return true;
}

int main(){
    int K,i,j,k,V,E,s,t;
    for(scanf("%d",&K);K;--K){
        scanf("%d%d",&V,&E);
        clause cl;
        for(;E--;){
            scanf("%d%d",&s,&t);
            if(s>0)s=VAR(s-1);else s=NOT(VAR(-s-1));
            if(t>0)t=VAR(t-1);else t=NOT(VAR(-t-1));
            cl.push_back(make_pair(s,t));
        }
        two_satisfiability(V,cl);
    }
}