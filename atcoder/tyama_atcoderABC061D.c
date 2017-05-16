#pragma GCC optimize("O3")
#include <stdio.h>
#define INF 2300000000000000000LL
long long dist[1000][1000];
int main(){
	int V,E,i,j;long long k;
	scanf("%d%d",&V,&E);
	for(i=0;i<V;i++){
		for(j=0;j<i;j++)dist[i][j]=INF;
		dist[i][j++]=0;
		for(;j<V;j++)dist[i][j]=INF;
	}
	for(;E--;)scanf("%d%d%lld",&i,&j,&k),dist[i-1][j-1]=-k;
	for(k=0;k<V;k++)for(i=0;i<V;i++)for(j=0;j<V;j++)
		if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][j]>dist[i][k]+dist[k][j])
			dist[i][j]=dist[i][k]+dist[k][j];
	for(i=0;i<V;i++)if(dist[0][i]!=INF&&dist[i][V-1]!=INF&&dist[i][i]<0){puts("inf");return 0;}
	printf("%lld\n",-dist[0][V-1]);
	return 0;
}