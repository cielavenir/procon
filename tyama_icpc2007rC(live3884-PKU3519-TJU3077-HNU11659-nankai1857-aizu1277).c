#define Z(l,L)for(;l--;)scanf("%d",&x),L[x]=1;
double P[102][101];L[101],B[101],N,T,l,b,t,n,k;main(x){for(;scanf("%d%d%d%d",&N,&T,&l,&b),N;printf("%f\n",P[T][N])){
for(n=0;n<=N;n++)for(L[n]=B[n]=t=0;t<=T;t++)P[t][n]=0;
Z(l,L)Z(b,B)
for(P[t=0][0]=1;t<T;P[t+1][N]+=P[t][N],t++)for(n=0;n<N;n++)for(k=0;++k<7;P[t+1+L[x]][x]+=P[t][n]/6)x=n+k,x=B[x=x>N?2*N-x:x]?0:x;
}exit(0);}