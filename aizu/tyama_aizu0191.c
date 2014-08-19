double x[100][100],y[100][100],r,z;
main(n,m,i,j,k){for(;scanf("%d%d",&n,&m),m;printf("%.2f\n",r)){
memset(x,0,sizeof(x));
for(i=0;i<n;i++)for(x[0][i]=1,j=0;j<n;j++)scanf("%lf",y[i]+j);
for(i=1;i<m;i++)for(j=0;j<n;j++)for(k=0;k<n;k++)if(x[i][j]<(z=x[i-1][k]*y[k][j]))x[i][j]=z;
for(r=j=0;j<n;j++)r=r<x[m-1][j]?x[m-1][j]:r;
}exit(0);}