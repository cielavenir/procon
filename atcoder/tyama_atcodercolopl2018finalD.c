#define X 999999
N,W[X],A[X][2],M=1000000007;
S(n){int r=0;for(;n;n-=n&-n)r+=W[n];return r;}
I(n){for(;n<X;n+=n&-n)W[n]++;}
main(i,x,z){
	long long y=scanf("%d",&N);
	for(i=-1;++i<N;A[i][0]=x,A[i][1]=y)if(scanf("%d%d",&x,&y),x<y)z=x,x=y,y=z;
	qsort(A,N,8,"H\x8b\7H+\6t\5H\x99\x92\f \xc3");
	for(y=i=1;++i<N;)y=2*y%M;
	for(x=0;N--;)x=(x+S(A[N][0]-1)*y)%M,I(A[N][0]),I(A[N][1]);
	printf("%d\n",x);
}
