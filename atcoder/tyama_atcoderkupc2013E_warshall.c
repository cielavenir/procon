#include <stdio.h>
int N[300],dist[300][300],dice[6];
main(){
	int M,s,g,i,j,k;
	//input
	scanf("%d",&M);
	for(i=0;i<6;i++)scanf("%d",dice+i);
	scanf("%d%d",&s,&g);s--,g--;
	for(i=0;i<M;i++)scanf("%d",N+i);
	//setup
	memset(dist,11,sizeof(dist));
	for(i=0;i<M;i++){
		dist[i][i]=0;
		for(j=0;j<6;j++){
			k=i+dice[j];
			if(k<M&&i!=k+N[k])dist[i][k+N[k]]=1;
			k=i-dice[j];
			if(k>=0&&i!=k+N[k])dist[i][k+N[k]]=1;
		}
	}
	//warshall-floyd
	for(k=0;k<M;k++)for(i=0;i<M;i++)for(j=0;j<M;j++)
		if(dist[i][j]>dist[i][k]+dist[k][j])dist[i][j]=dist[i][k]+dist[k][j];
	//interaction started
	int test,coor[3],cost[3];
	for(test=0;test<3000;test++){
		scanf("%d",&k);k=dice[k-1];
		coor[0]=s-k,coor[1]=s,coor[2]=s+k;
		cost[0]=coor[0]>=0?dist[coor[0]+=N[coor[0]]][g]:999;
		cost[1]=dist[coor[1]][g];
		cost[2]=coor[2]<M?dist[coor[2]+=N[coor[2]]][g]:999;
		for(k=0,j=1;j<3;j++)if(cost[k]>cost[j])k=j;
		printf("%d\n",k-1),fflush(stdout),s=coor[k];
		if(s==g)break;
	}
	if(test==3000)return 1;
}