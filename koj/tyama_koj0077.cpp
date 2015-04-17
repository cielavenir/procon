#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	const int mod=1000000007;
	int N,M;
	scanf("%d%d",&N,&M);
	vector<vector<unsigned int> >dp(N+1);
	vector<int>a(N);
	for(int i=0;i<=N;i++){
		dp[i].resize(M+1);
		dp[i][0]=1;
		if(i<N)scanf("%d",&a[i]);
	}
	for(int i=0;i<N;i++)for(int j=1;j<=M;j++){
		if(j-1-a[i]>=0)dp[i+1][j]=(dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]]+mod)%mod;
		else dp[i+1][j]=(dp[i+1][j-1]+dp[i][j])%mod;
	}
	printf("%d\n",dp[N][M]);
}