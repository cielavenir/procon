int dist[1001][1001];
main(){
	int a,b,c,t,k,n,i,j;
	scanf("%d%d",&n,&k);
		/*initialize*/
		memset(dist,11,sizeof(dist));
		for(i=1;i<=n;i++)dist[i][i]=0;
		for(;k;k--){
			scanf("%d%d%d",&a,&b,&c);
			dist[a][b]=c;
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
			for(i=1;i<=n;i++){
				if(dist[1][i]<99999)printf("%d",dist[1][i]);
				else putchar('x');
				putchar(i<n?' ':'\n');
			}
		}
}