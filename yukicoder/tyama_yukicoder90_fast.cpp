#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
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
	int N = 1 << n;
	REP(S,N) REP(i,n) best[S][i] = 0;
	REP(S,N) REP(j,n) if (!(S&(1<<j))) {
		int score = 0;
		REP(i,n) if (S&(1<<i)) score+=w[i][j];
		REP(i,n) if (best[S|(1<<j)][j] <= best[S][i] + score) {
			best[S|(1<<j)][j] = best[S][i] + score;
			::prev[S|(1<<j)][j] = i;
		}
	}
	int t = max_element(best[N-1], best[N-1]+n) - best[N-1];
	//path.clear(); buildPath(N-1, t, path);
	return best[N-1][t];
}

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	Matrix m(N);
	for(int i=0;i<N;i++)m[i].resize(N);
	for(;M--;){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		m[a][b]=c;
	}
	vector<int> path;
	printf("%d\n",shortestHamiltonPath(m,path));
}