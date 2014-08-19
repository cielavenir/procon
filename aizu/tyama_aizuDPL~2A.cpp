#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define INF 9999999
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

const int M = 20;
Weight best[1<<M][M];
int    prev[1<<M][M];
void buildPath(int S, int i, vector<int> &path) {
  if (!S) return;
  buildPath(S^(1<<i), prev[S][i], path);
  path.push_back(i);
}
Weight shortestHamiltonCycle(Matrix w, vector<int> &path) {
  int n=w.size();
  int N = 1 << n;
  REP(S,N) REP(i,n) best[S][i] = INF;
  best[0][0] = 0;
  REP(S,N) REP(i,n) REP(j,n) if (!(S&(1<<j)))
    if (best[S|(1<<j)][j] > best[S][i] + w[i][j])
      best[S|(1<<j)][j] = best[S][i] + w[i][j],
      prev[S|(1<<j)][j] = i;
  //int t = min_element(best[N-1], best[N-1]+n) - best[N-1];
  //path.clear(); buildPath(N-1, t, path);
  return best[N-1][0]==INF ? -1 : best[N-1][0];
}

int main(){
	int V,E,s,t,d;
	scanf("%d%d",&V,&E);
	Matrix m(V,Array(V));
	for(s=0;s<V;s++)for(t=0;t<V;t++)if(s!=t)m[s][t]=INF;
	vector<int>path;
	for(;E--;)scanf("%d%d%d",&s,&t,&d),m[s][t]=d;
	printf("%d\n",shortestHamiltonCycle(m,path));
}