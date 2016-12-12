E[10002],W[10002],M,R,i=-1,j;
main(N){
	for(scanf("%d%d",&N,&M),getchar();++i<M;getchar())for(j=0;++j<=N;)getchar()-87?E[j]++:W[j]++;
	for(M*=j=N;--j;W[j]+=W[j+1])E[N-j+1]+=E[N-j];
	for(j=-1;++j<=N;)M>E[j]+W[j+1]?M=E[R=j]+W[j+1]:1;
	R=!printf("%d %d\n",R,R+1);
}