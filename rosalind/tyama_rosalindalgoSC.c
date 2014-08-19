int dist[1001][1001];
main(){
	int a,b,c,t,k,n,i,j;
	for(scanf("%d",&t);t;putchar(--t?' ':'\n')){
		scanf("%d%d",&n,&k);
		/*initialize*/
		memset(dist,11,sizeof(dist));
		for(i=1;i<=n;i++)dist[i][i]=0;
		for(;k;k--){
			scanf("%d%d",&a,&b);
			dist[a][b]=1;
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
			for(j=1;j<=n;j++)for(i=j+1;i<=n;i++)
				if(dist[j][i]>99999&&dist[i][j]>99999)goto fail;
			printf("1");continue;
fail:
			printf("-1");
		}
	}
}