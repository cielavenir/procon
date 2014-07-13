#include <stdio.h>
#define INF 1000000000
int dist[300][300];
int main(){
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<i;j++)dist[i][j]=INF;
		dist[i][i]=0;
		for(j=i+1;j<n;j++)dist[i][j]=INF;
	}
	for(;m--;){
		scanf("%d%d%d",&i,&j,&k);
		dist[i-1][j-1]=dist[j-1][i-1]=k;
	}
	for(k=0;k<n;k++)for(i=0;i<n;i++)for(j=0;j<n;j++){
		if(dist[i][j]>dist[i][k]+dist[k][j])dist[i][j]=dist[i][k]+dist[k][j];
	}
	m=INF;
	for(i=0;i<n;i++){
		k=0;
		for(j=0;j<n;j++)if(i!=j&&k<dist[i][j])k=dist[i][j];
		if(m>k)m=k;
	}
	printf("%d\n",m);
	return 0;
}