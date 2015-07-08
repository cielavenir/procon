#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int n,m;
	scanf("%d",&n);
	vector<int>cost(n);
	vector<vector<long long> >dist(n);
	for(int i=0;i<n;i++){
		scanf("%d",&cost[i]);
		dist[i].resize(n);
		for(int j=0;j<n;j++)dist[i][j]=1LL<<61;
		dist[i][i]=0;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		dist[a][b]=dist[b][a]=c;
	}
	for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)
		if(dist[i][j]>dist[i][k]+dist[k][j])dist[i][j]=dist[i][k]+dist[k][j];
	long long ma=1LL<<61;
	for(int i=1;i<n-1;i++)for(int j=1;j<n-1;j++)
		if(i!=j&&ma>dist[0][i]+cost[i]+dist[i][j]+cost[j]+dist[j][n-1])ma=dist[0][i]+cost[i]+dist[i][j]+cost[j]+dist[j][n-1];
	printf("%lld\n",ma);
}