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
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

const int M = 20;
Weight best[1<<M];
Weight total[1<<M];
Weight shortestHamiltonPath(const Array &w) {
	int n=w.size();
	int N = 1 << n;
	REP(S,N) best[S] = total[S] = 0;
	best[0] = total[0] = 100;
	REP(S,N) REP(j,n) if (!(S&(1<<j)) && best[S]>0) {
		if (w[j]>0) {
			Weight hp=min(best[S]+w[j],total[S]);
			if (best[S|(1<<j)] < hp) {
				best[S|(1<<j)] = hp;
				total[S|(1<<j)] = total[S];
			}
		} else {
			Weight hp=best[S]+w[j];
			if (hp<=0) continue;
			if (total[S|(1<<j)] < total[S]+100 || (total[S|(1<<j)] == total[S]+100 && best[S|(1<<j)] < hp)) {
				best[S|(1<<j)] = hp;
				total[S|(1<<j)] = total[S]+100;
			}
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