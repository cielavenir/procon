#include <stdio.h>
#define M 1001
int dist[M][M];
int main(){
	int n,m,s,g1,g2,i,j,k,l;
	for(;scanf("%d%d%d%d%d",&n,&m,&s,&g1,&g2),n;){
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)dist[i][j]=(i!=j)*(1<<29);
		for(i=0;i<m;i++)scanf("%d%d%d",&j,&k,&l),dist[j][k]=l;
		for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++){
			if(dist[i][j]>dist[i][k]+dist[k][j])dist[i][j]=dist[i][k]+dist[k][j];
		}
		for(m=1<<29,i=1;i<=n;i++){
			if(m>dist[s][i]+dist[i][g1]+dist[i][g2])m=dist[s][i]+dist[i][g1]+dist[i][g2];
		}
		printf("%d\n",m);
	}
	return 0;
}