#define max(a,b) ((a)>(b)?(a):(b))
int p[9999];

solve(int n,int m,int c){
  int i,j,k;
  double d=0;
  for(i=0;i<m;i++)p[i]=1;
  for(i=1;i<n;i++)
    for(j=(i+1)*(m-1);~j;j--)
      for(k=j-1;k>=max(0,j-(m-1));k--)
        p[j]+=p[k];
  for(i=0;i<=n*(m-1);i++)
    d+=p[i]*(i+n>c?i+n-c:1);
  for(i=0;i<n;i++)d/=m;
  printf("%.8lf\n",d);
}

main(){
  int n,m,k;
  while(scanf("%d%d%d",&n,&m,&k),n){
    memset(p,0,sizeof(p));
    solve(n,m,k);
  }
}