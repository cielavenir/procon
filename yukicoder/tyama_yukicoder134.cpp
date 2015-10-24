#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define INF 99999999
using namespace std;

typedef double Weight;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

const int M = 20;
Weight best[1<<M][M];
Weight total[1<<M][M];
Weight shortestHamiltonPath(const Matrix &dist, const Array &cost) {
	int n=cost.size();
	int N = 1 << n;
	REP(S,N) REP(i,n) best[S][i] = INF;
	best[0][0] = 0;
	total[0][0] = 0;
	REP(i,n) total[0][0] += cost[i];
	REP(S,N) REP(j,n) if (!(S&(1<<j))) REP(i,n) {
		Weight time = dist[i][j]*(total[S][i]+100)/120 + cost[j];
		if (best[S|(1<<j)][j] >= best[S][i] + time) {
			best[S|(1<<j)][j] = best[S][i] + time;
			total[S|(1<<j)][j] = total[S][i] - cost[j];
		}
	}
	//int t = max_element(best[N-1], best[N-1]+n) - best[N-1];
	//path.clear(); buildPath(N-1, t, path);
	return best[N-1][0];
}

int main(){
	double X,Y;
	int N;
	scanf("%lf%lf%d",&X,&Y,&N);
	Array cost(N+1);
	Matrix dist(N+1);dist[0].resize(N+1);
	{
		vector<pair<double,double> >a(N+1);
		a[0].first=X,a[0].second=Y;
		for(int i=1;i<=N;i++){
			dist[i].resize(N+1);
			scanf("%lf%lf%lf",&a[i].first,&a[i].second,&cost[i]);
		}
		for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)dist[i][j]=fabs(a[i].first-a[j].first)+fabs(a[i].second-a[j].second);
	}
	printf("%f\n",shortestHamiltonPath(dist,cost));
}