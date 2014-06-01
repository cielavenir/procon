#include <stdio.h>
#define INF 2100000000
int dist[100][100];
int main(){
	int V,E,i,j,k;
	scanf("%d%d",&V,&E);
	for(i=0;i<V;i++){
		for(j=0;j<i;j++)dist[i][j]=INF;
		dist[i][j++]=0;
		for(;j<V;j++)dist[i][j]=INF;
	}
	for(;E--;)scanf("%d%d%d",&i,&j,&k),dist[i][j]=k;
	for(k=0;k<V;k++)for(i=0;i<V;i++)for(j=0;j<V;j++)
		if(dist[i][k]<INF && dist[k][j]<INF && dist[i][j]>dist[i][k]+dist[k][j])
			dist[i][j]=dist[i][k]+dist[k][j];
	for(i=0;i<V;i++)if(dist[i][i]<0){puts("NEGATIVE CYCLE");return 0;}
	for(i=0;i<V;i++)for(j=0;j<V;j++){
		if(dist[i][j]==INF)printf("INF");
		else printf("%d",dist[i][j]);
		printf(j<V-1?" ":"\n");
	}
	return 0;
}