long long a[50],A[50];
int main(T,N,M,i,j,c){for(scanf("%d",&T);T--;){
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++)scanf("%lld",A+i);
	for(i=0;i<N;i++){
		memcpy(a,A,sizeof(A));
		for(j=0;j<M;j++){
			c=(i+j)%N;
			a[c]=(a[c]+a[(c+N-1)%N]+a[(c+1)%N])%1000000007;
		}
		for(j=0;j<N;j++)printf(j<N-1?"%lld ":"%lld\n",a[j]);
	}
	if(T)puts("");
}return 0;}