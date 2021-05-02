#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long Weight;
struct Edge {
  int src, dst;
  Edge(int src, int dst) :
    src(src), dst(dst) { }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

#define EVEN(x) (mu[x] == x || (mu[x] != x && phi[mu[x]] != mu[x]))
#define ODD(x)  (mu[x] != x && phi[mu[x]] == mu[x] && phi[x] != x)
#define OUTER(x) (mu[x] != x && phi[mu[x]] == mu[x] && phi[x] == x)
int maximumMatching(const Graph &g, Edges &matching) {
  int n = g.size();
  vector<int> mu(n), phi(n), rho(n), scanned(n);
  REP(v,n) mu[v] = phi[v] = rho[v] = v; // (1) initialize
  for (int x = -1; ; ) {
    if (x < 0) {                        // (2) select even
      for (x = 0; x < n && (scanned[x] || !EVEN(x)); ++x);
      if (x == n) break;
    }
    int y = -1;                         // (3) select incident
    FOR(e, g[x]) if (OUTER(e->dst) || (EVEN(e->dst) && rho[e->dst] != rho[x])) y = e->dst;
    if (y == -1) scanned[x] = true, x = -1;
    else if (OUTER(y)) phi[y] = x;      // (4) growth
    else {
      vector<int> dx(n, -2), dy(n, -2); // (5,6), !TRICK! x % 2 --> x >= 0
      for (int k = 0, w = x; dx[w] < 0; w = k % 2 ? mu[w] : phi[w]) dx[w] = k++;
      for (int k = 0, w = y; dy[w] < 0; w = k % 2 ? mu[w] : phi[w]) dy[w] = k++;
      bool vertex_disjoint = true;
      REP(v,n) if (dx[v] >= 0 && dy[v] > 0) vertex_disjoint = false;
      if (vertex_disjoint) {            // (5) augment
        REP(v,n) if (dx[v] % 2) mu[phi[v]] = v, mu[v] = phi[v];
        REP(v,n) if (dy[v] % 2) mu[phi[v]] = v, mu[v] = phi[v];
        mu[x] = y; mu[y] = x; x = -1;
        REP(v,n) phi[v] = rho[v] = v, scanned[v] = false;
      } else {                          // (6) shrink
        int r = x, d = n;
        REP(v,n) if (dx[v] >= 0 && dy[v] >= 0 && rho[v] == v && d > dx[v]) d = dx[v], r = v;
        REP(v,n) if (dx[v] <= d && dx[v] % 2 && rho[phi[v]] != r) phi[phi[v]] = v;
        REP(v,n) if (dy[v] <= d && dy[v] % 2 && rho[phi[v]] != r) phi[phi[v]] = v;
        if (rho[x] != r) phi[x] = y;
        if (rho[y] != r) phi[y] = x;
        REP(v,n) if (dx[rho[v]] >= 0 || dy[rho[v]] >= 0) rho[v] = r;
      }
    }
  }
  matching.clear();
  REP(u,n) if (u < mu[u]) matching.push_back( Edge(u, mu[u]) );
  return matching.size(); // make explicit matching
}

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	vector<int>v(N);
	Graph g(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	for(int i=0;i<N;i++)for(int j=i+1;j<N;j++){
		if(v[i]==v[j] || (v[i]+v[j])%M==0){
			g[i].emplace_back(i,j);
			g[j].emplace_back(j,i);
		}
	}
	Edges e;
	printf("%d\n",maximumMatching(g,e));
}
