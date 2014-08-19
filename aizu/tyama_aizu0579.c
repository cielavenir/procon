#define M 200
T[M],A[M],B[M],C[M],Z[M][M],d;
main(D,n,i,j,x){
	memset(Z,0xff,sizeof(Z));
	for(scanf("%d%d",&D,&n);d<D;d++)scanf("%d",T+d);
	for(i=0;i<n;i++)if(scanf("%d%d%d",A+i,B+i,C+i),A[i]<=T[0]&&T[0]<=B[i])Z[0][i]=0;
	for(d=0;d<D-1;d++)for(i=0;i<n;i++)if(~Z[d][i])for(j=0;j<n;j++)if(A[j]<=T[d+1]&&T[d+1]<=B[j])if(x=Z[d][i]+abs(C[i]-C[j]),Z[d+1][j]<x)Z[d+1][j]=x;
	for(x=i=0;i<n;i++)if(x<Z[D-1][i])x=Z[D-1][i];
	printf("%d\n",x);
exit(0);}