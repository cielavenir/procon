#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int cost[101][101];
int main(){
	int c,N,m,i,j,k,x,y;
	for(;scanf("%d%d%d",&N,&m,&c),N;){
		vector<map<int,int> >dist(N+1);
		vector<map<int,int> >fee(N+1);
		memset(cost,99,sizeof(cost));
		for(k=0;k<m;k++){
			scanf("%d%d%d%d",&i,&j,&x,&y);
			dist[i][j]=dist[j][i]=y;
			fee[i][j]=fee[j][i]=x;
		}
		for(i=0;i<=c;i++)cost[1][i]=0;
		for(;~c;c--){
			vector<bool>used(N+1);
			for(;;){ //dijkstra
				int m=1e9;
				for(i=1;i<=N;i++)if(!used[i]&&m>cost[i][c])m=cost[i][c];
				if(m==1e9)break;
				for(j=1;j<=N;j++)if(m==cost[j][c]){
					map<int,int>::iterator it=dist[j].begin();
					for(used[j]=1;it!=dist[j].end();it++){
						if(cost[it->first][c]>it->second+cost[j][c])cost[it->first][c]=it->second+cost[j][c];
						if(fee[j][it->first]<=c&&cost[it->first][max(0,c-fee[j][it->first])]>cost[j][c])
							cost[it->first][max(0,c-fee[j][it->first])]=cost[j][c];
					}
				}
			}
		}
		printf("%d\n",cost[N][0]);
	}
}