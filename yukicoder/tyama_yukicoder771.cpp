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
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

const int M = 20;
Weight best[1<<M][M];
int    prev[1<<M][M];
void buildPath(int S, int i, vector<int> &path) {
  if (!S) return;
  buildPath(S^(1<<i), ::prev[S][i], path);
  path.push_back(i);
}
Weight shortestHamiltonPath(const Matrix &w, vector<int> &path) {
  int n=w.size();
  int N = 1 << n, K;
  REP(S,N) REP(i,n) best[S][i] = INF;
  REP(S,N) REP(i,n) if(S&1<<i) REP(j,n) if (!(S&(1<<j)))
    if (K=best[S][i]==INF ? w[i][j] : max(best[S][i],w[i][j]), best[S|(1<<j)][j] > K)
      best[S|(1<<j)][j] = K,
      ::prev[S|(1<<j)][j] = i;
  int t = min_element(best[N-1], best[N-1]+n) - best[N-1];
  //path.clear(); buildPath(N-1, t, path);
  return best[N-1][t];
}

int main(){
	int V,s,t,d;
	scanf("%d",&V);
	Matrix m(V,Array(V));
	{
		vector<pair<int,int> >v(V);
		for(int i=0;i<V;i++)scanf("%d%d",&v[i].first,&v[i].second);
		for(s=0;s<V;s++)for(t=0;t<V;t++)if(s!=t){
			m[s][t]=v[s].second-v[s].first+v[t].first;
		}
	}
	vector<int>path;
	printf("%d\n",shortestHamiltonPath(m,path));
}
