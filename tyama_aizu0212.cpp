#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int cost[101][11];
int main(){
	int c,N,m,s,d,i,j,k,x;
	for(;scanf("%d%d%d%d%d",&c,&N,&m,&s,&d),N;){
		vector<map<int,int> >dist(N+1);
		memset(cost,99,sizeof(cost));
		for(k=0;k<m;k++){
			scanf("%d%d%d",&i,&j,&x);dist[i][j]=dist[j][i]=x;
		}
		for(i=0;i<=c;i++)cost[s][i]=0;
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
						if(c&&cost[it->first][c-1]>it->second/2+cost[j][c])cost[it->first][c-1]=it->second/2+cost[j][c];
					}
				}
			}
		}
		printf("%d\n",cost[d][0]);
	}
}