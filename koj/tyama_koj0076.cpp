#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	const int mod=1000000007;
	int N,M;
	scanf("%d%d",&N,&M);
	vector<vector<int> >dp(M+1);
	for(int i=0;i<=M;i++)dp[i].resize(N+1);
	dp[0][0]=1;
	for(int i=1;i<=M;i++)for(int j=0;j<=N;j++){
		if(j-i>=0)dp[i][j]=(dp[i-1][j]+dp[i][j-i])%mod;
		else dp[i][j]=dp[i-1][j];
	}
	printf("%d\n",dp[M][N]);
}