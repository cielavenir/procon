//from PKU1125
main(){
	int i,j,n,k,K,a,b,d,dist[10][10];
	for(;scanf("%d",&k),k;printf("%d %d\n",K,k)){
		/*initialize*/
		memset(dist,11,sizeof(dist));
		for(i=0;i<=9;i++)dist[i][i]=0;
		for(n=0;k;k--){
			scanf("%d%d%d",&a,&b,&d);
			if(n<b)n=b;
			dist[a][b]=d,dist[b][a]=d;
		}

		{/*warshall-floyd*/
			int k,i,j;
			for(k=0;k<=n;k++)
				for(i=0;i<=n;i++)
					for(j=0;j<=n;j++)
						if(dist[i][j]>dist[i][k]+dist[k][j])
							dist[i][j]=dist[i][k]+dist[k][j];
		}

		for(k=1e9,i=0;i<=n;i++){
			for(d=j=0;j<=n;j++)d+=dist[i][j];
			if(k>d)k=d,K=i;
		}
	}
	exit(0);
}