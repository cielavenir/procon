//from PKU1125
main(){
	int i,n,k,a,b,A,B,dist[101][101];
	scanf("%d%d",&n,&k);
		/*initialize*/
		memset(dist,11,sizeof(dist));
		for(i=1;i<=n;i++)dist[i][i]=0;
		for(;k;k--){
			scanf("%d,%d,%d,%d",&a,&b,&A,&B);
			dist[a][b]=A,dist[b][a]=B;
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
			scanf("%d,%d,%d,%d",&a,&b,&A,&B);
			printf("%d\n",A-B-dist[a][b]-dist[b][a]);
		}
	exit(0);
}