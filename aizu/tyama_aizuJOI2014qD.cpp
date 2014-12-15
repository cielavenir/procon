#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	vector<int>dist(N);
	for(int i=0;i<N;i++)scanf("%d",&dist[i]);
	vector<int>climate(M);
	for(int i=0;i<M;i++)scanf("%d",&climate[i]);
	vector<vector<int> >m(N+1);
	for(int i=0;i<=N;i++){
		m[i].resize(M+1);
		for(int j=0;j<=M;j++)m[i][j]=999999999;
	}
	for(int i=0;i<=M;i++)m[0][i]=0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++)m[i][j]=min(m[i][j-1],m[i-1][j-1]+dist[i-1]*climate[j-1]);
	}
	int result=m[N][0];
	for(int i=0;i<=M;i++)result=min(result,m[N][i]);
	printf("%d\n",result);
}