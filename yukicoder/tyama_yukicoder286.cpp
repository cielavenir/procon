#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define INF 99999999
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
Weight best[1<<M];
Weight total[1<<M];
Weight shortestHamiltonPath(const Array &w) {
	int n=w.size();
	int N = 1 << n;
	REP(S,N) best[S] = total[S] = INF;
	best[0] = total[0] = 0;
	REP(S,N) REP(j,n) if (!(S&(1<<j))) {
		Weight discount=total[S]%1000;
		Weight discounted=max(0,w[j]-discount);
		if (best[S|(1<<j)] > best[S] + discounted) {
			best[S|(1<<j)] = best[S] + discounted;
			total[S|(1<<j)] = total[S] + w[j];
		}
	}
	return best[N-1];
}

int main(){
	int N;
	scanf("%d",&N);
	Array v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	printf("%d\n",shortestHamiltonPath(v));
}