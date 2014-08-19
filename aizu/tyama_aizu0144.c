//from PKU1125
main(){
	int i,n,f,k,t,dist[101][101];
	scanf("%d",&n);
		/*initialize*/
		memset(dist,11,sizeof(dist));
		for(i=1;i<=n;i++){
			dist[i][i]=0;
			scanf("%d%d",&f,&k);
			for(;k;k--){
				scanf("%d",&t);
				dist[f][t]=1;
			}
		}

		{/*warshall-floyd*/
			int k,i,j;
			for(k=1;k<=n;k++)
				for(i=1;i<=n;i++)
					for(j=1;j<=n;j++)
						if(dist[i][j]>dist[i][k]+dist[k][j])
							dist[i][j]=dist[i][k]+dist[k][j];
		}

		{/*query*/
			for(scanf("%d",&k);k;k--){
				scanf("%d%d%d",&f,&t,&n);
				printf(dist[f][t]<n?"%d\n":"NA\n",dist[f][t]+1);
			}
		}
	exit(0);
}