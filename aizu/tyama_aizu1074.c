char names[20][16];
int M[20][30],S[30],P[20];
main(n,m,i,j,d){
  for(;scanf("%d",&n),n;printf("%d %s\n",P[d],names[d])){
    memset(names,0,sizeof names),
    memset(M,0,sizeof M),
    memset(S,0,sizeof S),
    memset(P,0,sizeof P);
    for(i=0;i<n;i++)
      for(scanf("%s%d",names[i],&m),j=0;j<m;j++)scanf("%d",&d),M[i][d]++,S[d]++;
    for(i=0;i<n;i++)
      for(j=0;j<30;j++)
        if(M[i][j])P[i]+=1+n-S[j];
    for(d=0,m=1e9,i=0;i<n;i++)
      if(P[i]<m||(P[i]==m&&strcmp(names[i],names[d])<0))d=i,m=P[i];
  }
  exit(0);
}