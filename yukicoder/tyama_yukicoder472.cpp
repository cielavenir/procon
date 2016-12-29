#pragma GCC optimize("O3")
#include <stdio.h>
int v[5000][4],n;
int memo[5000][15001];
int dfs(int d,int r){
	if(d==n)return 0;
	if(!memo[d][r]){
		memo[d][r]=1<<30;
		int rem=(n-d)*3;
		if(rem>=r)for(int i=0;i<=(r<3?r:3);i++)if(memo[d][r]>dfs(d+1,r-i)+v[d][i])memo[d][r]=dfs(d+1,r-i)+v[d][i];
	}
	return memo[d][r];
}
int main(){
	int k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;v[i][3]=1,i++)for(int j=0;j<3;j++)scanf("%d",v[i]+j);
	printf("%f\n",dfs(0,k)*1.0/n);
}
