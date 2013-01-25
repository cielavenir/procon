long long n[99][21];a[100],i,j;main(N){
for(scanf("%d",&N);i<N;)scanf("%d",a+i++);
for(n[0][a[0]]=i=1;i<N-1;i++)for(j=0;j<=20;j++)0<=j-a[i]&&(n[i][j-a[i]]+=n[i-1][j]),j+a[i]<=20&&(n[i][j+a[i]]+=n[i-1][j]);
printf("%lld\n",n[N-2][a[N-1]]);exit(0);}