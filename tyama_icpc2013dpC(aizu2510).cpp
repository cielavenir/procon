#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
int dp[1001][1001];
main(){
	int N,r,w,rL,mw,i,j;
	for(;~scanf("%d",&N),N;){
		vector<pii>v;
		for(i=0;i<N;i++)scanf("%d%d",&r,&w),v.push_back(make_pair(r,w));
		sort(v.begin(),v.end());
		pii m=v[v.size()-1];
		rL=m.first;
		for(r=w=i=0;i<N-1;i++)r+=v[i].first,w+=v[i].second;
		if(r>=rL){
			printf("%d\n",r+w+rL+m.second);
		}else{
			memset(dp,0,sizeof(dp));
			// http://acm-icpc.aitea.net/index.php?2013%2FPractice%2F%CC%CF%B5%BC%B9%F1%C6%E2%CD%BD%C1%AA%2F%B9%D6%C9%BE
			dp[0][0] = 1;
			for(i=0;i<N-1;i++){
				// rL-rが本Lを読むまでに生じる待ち時間
				for(j=0;j<=rL-r;j++)if(dp[i][j]){
					dp[i+1][j] = 1;
					if(j+v[i].second<=rL-r)dp[i+1][j+v[i].second]=1;
				}
			}
			for(mw=i=0;i<=rL-r;i++)if(dp[N-1][i])mw=i; // 待ち時間に書ける感想文の最大量
			printf("%d\n",2*rL+w+m.second-mw);
		}
	}
}