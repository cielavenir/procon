main(){
  int n,i,c,a,b,dist[101][101];
  while(scanf("%d",&n),n){
    /*initialize*/
    memset(dist,11,sizeof(dist));
    for(i=1;i<=n;i++){
      dist[i][i]=0;
      scanf("%d",&c);
      for(;c;c--){
        scanf("%d%d",&a,&b);
        dist[i][a]=b;
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

    {/*finalize*/
      int p,r=991,m,i,j; /* 10*99 */
      for(i=1;i<=n;i++){
        m=0;
        for(j=1;j<=n;j++)
          if(m<dist[i][j])m=dist[i][j];
        if(m<r)p=i,r=m;
      }
      printf(r>990?"disjoint.\n":"%d %d\n",p,r);
    }
  }
}