//from PKU1125
#define M 299
double dist[M][M],d;
next[M][M],x[M],y[M];
main(){
	int k,n,i,j;
	for(;scanf("%d",&n),n;){
		/*initialize*/
		for(i=1;i<=n;i++)scanf("%d",&j),scanf("%d%d",x+j,y+j);
		for(i=1;i<=n;i++)for(j=1;j<=n;next[i][j]=j,j++)
			dist[i][j]=(d=hypot(x[i]-x[j],y[i]-y[j]))<50.1?d:M;

		{/*warshall-floyd*/
			int k,i,j;
			for(k=1;k<=n;k++)
				for(i=1;i<=n;i++)
					for(j=1;j<=n;j++){
						if(dist[i][j]>dist[i][k]+dist[k][j])
							dist[i][j]=dist[i][k]+dist[k][j],next[i][j]=next[i][k];
					}
		}

		{/*query*/
			for(scanf("%d",&k);k;k--){
				if(scanf("%d%d",&i,&j),dist[i][j]>=M){puts("NA");continue;}
				for(n=i;n!=j;n=next[n][j])printf("%d ",n);
				printf("%d\n",j);
			}
		}
	}exit(0);
}