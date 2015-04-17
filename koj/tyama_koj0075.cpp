#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	vector<int>a(N),m(N),dp(K+1);
	for(int i=0;i<N;i++)scanf("%d%d",&a[i],&m[i]);
	fill(dp.begin()+1,dp.end(),-1);
	for(int i=0;i<N;i++)for(int j=0;j<=K;j++){
		if(dp[j]>=0)dp[j]=m[i];
		else if(j<a[i] || dp[j-a[i]]<=0)dp[j]=-1;
		else dp[j]=dp[j-a[i]]-1;
	}
	puts(dp[K]>=0 ? "Yes" : "No");
}