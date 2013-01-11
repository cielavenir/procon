i,j,c,b,v,u,D[10000];main(N,K,T,U,V,L,x){
scanf("%d%d%d%d%d%d",&N,&K,&T,&U,&V,&L);
for(;i<N;i++)scanf("%d",&x),D[x]=1;
for(;j<L;b?v++,b--:u++,j++)if((c+=D[j])>K||c&&!b)c--,b=T*V;
printf("%f\n",1.*v/V+1.*u/U);
exit(0);}