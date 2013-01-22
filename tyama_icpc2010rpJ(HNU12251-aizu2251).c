int t,n,m,l,i,j,a,b,k,P[1001],T[1001],Q[2001],C[2001][2001],V[2001],d[1001][1001];
int match(s){int i=l;for(;i<l+l;i++)if(C[s][i]&&!V[i])if(V[i]=1,Q[i]<0||match(Q[i]))return Q[s]=i,Q[i]=s,1;return 0;}
main(){
  for(;scanf("%d%d%d",&n,&m,&l),l;printf("%d\n",l-t)){
	memset(C,0,sizeof(C));memset(Q,0xff,sizeof(Q));
    for(i=0;i<n;i++)for(j=0;j<n;j++)d[i][j]=i==j?0:999999;
    for(i=0;i<m;i++)scanf("%d%d%d",&a,&b,&k),d[a][b]=d[b][a]=k;
	for(i=0;i<l;i++)scanf("%d%d",P+i,T+i);
	for(k=0;k<n;k++)for(i=0;i<n;i++)for(j=0;j<n;j++)if(d[i][j]>d[i][k]+d[k][j])d[i][j]=d[i][k]+d[k][j];
	for(i=0;i<l;i++)for(j=0;j<l;j++)if(i!=j&&d[P[i]][P[j]]<999999&&T[i]+d[P[i]][P[j]]<=T[j])C[i][l+j]=C[l+j][i]=1;
    for(t=i=0;i<l;i++)memset(&V,0,sizeof(V)),t+=match(i);
  }
  return 0;
}