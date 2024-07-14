#include <vector>
#include <tuple>
#include <cstdio>
#include <cmath>
#define INF 999999999
using namespace std;

#define MA 20
int M[MA][MA];
int best[1<<MA][MA];
int shortestHamiltonCycle(int n) {
	int N = 1 << n;
	int S,i,j;
	for(S=0;S<N;S++)for(i=0;i<n;i++)best[S][i]=INF;
	best[0][0]=0;
	for(S=0;S<N;S++)for(j=0;j<n;j++)if(!(S&(1<<j))){
		for(i=0;i<n;i++)if(best[S|(1<<j)][j] > best[S][i] + M[i][j]){
			best[S|(1<<j)][j] = best[S][i] + M[i][j];
		}
	}
	return best[N-1][0]==INF ? -1 : best[N-1][0];
}

int main(){
	int N,x,y,z;
  scanf("%d",&N);
	vector<tuple<int,int,int>>v;
	for(int i=0;i<N;i++){
    scanf("%d%d%d",&x,&y,&z);
    v.emplace_back(x,y,z);
	}
	for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
		  M[i][j]=abs(get<0>(v[j])-get<0>(v[i])) + abs(get<1>(v[j])-get<1>(v[i])) + max(0,get<2>(v[j])-get<2>(v[i]));
    }
	}
	printf("%d\n",shortestHamiltonCycle(N));
}
