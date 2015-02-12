#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<pair<int,int>,pair<int,int> > Troute;
int main(){
	int N,C,V,S,T,Y,M;
	scanf("%d%d%d",&N,&C,&V);
	vector<Troute> routes(V);
	vector<vector<int> >dist(C+1);
	for(int i=0;i<=C;i++)dist[i].resize(N);
	dist[0][0]=1;
	for(int i=0;i<V;i++)scanf("%d",&routes[i].first.first),routes[i].first.first--;
	for(int i=0;i<V;i++)scanf("%d",&routes[i].first.second),routes[i].first.second--;
	for(int i=0;i<V;i++)scanf("%d",&routes[i].second.first);
	for(int i=0;i<V;i++)scanf("%d",&routes[i].second.second);
	sort(routes.begin(),routes.end());
	for(int i=0;i<V;i++)for(int j=0;j<=C-routes[i].second.first;j++){
		if(!dist[j][routes[i].first.first])continue;
		if(
			!dist[j+routes[i].second.first][routes[i].first.second] ||
			dist[j][routes[i].first.first]+routes[i].second.second<dist[j+routes[i].second.first][routes[i].first.second]
		)
			dist[j+routes[i].second.first][routes[i].first.second]=dist[j][routes[i].first.first]+routes[i].second.second;
	}
	int mi=1<<20;
	for(int i=0;i<=C;i++)if(dist[i][N-1]>0&&mi>=dist[i][N-1])mi=dist[i][N-1]-1;
	printf("%d\n",mi==(1<<20)?-1:mi);
}