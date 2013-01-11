//from PKU1125
main(){
	int a,b,c,t,k,n,i,j,time[101][101],cost[101][101];
	for(;scanf("%d%d",&k,&n),n;){
		/*initialize*/
		memset(time,11,sizeof(time));
		memset(cost,11,sizeof(cost));
		for(i=1;i<=n;i++)time[i][i]=cost[i][i]=0;
		for(;k;k--){
			scanf("%d%d%d%d",&a,&b,&c,&t);
			time[a][b]=time[b][a]=t;
			cost[a][b]=cost[b][a]=c;
		}

		{/*warshall-floyd*/
			int k,i,j;
			for(k=1;k<=n;k++)
				for(i=1;i<=n;i++)
					for(j=1;j<=n;j++){
						if(time[i][j]>time[i][k]+time[k][j])
							time[i][j]=time[i][k]+time[k][j];
						if(cost[i][j]>cost[i][k]+cost[k][j])
							cost[i][j]=cost[i][k]+cost[k][j];
					}
		}

		{/*query*/
			for(scanf("%d",&k);k;k--){
				scanf("%d%d%d",&a,&b,&t);
				printf("%d\n",t?time[a][b]:cost[a][b]);
			}
		}
	}exit(0);
}