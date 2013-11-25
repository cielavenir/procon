m[21][11][156],n,k,s;main(N){
for(;N<21;N++)for(m[N][0][0]=n=1;n<=N;n++)for(k=10;k;k--)for(s=155;s-n>=0;s--)m[N][k][s]+=m[N][k-1][s-n];
for(;scanf("%d%d%d",&n,&k,&s),n;)printf("%d\n",m[n][k][s]);
}