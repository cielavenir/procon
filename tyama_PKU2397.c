#define max(a,b) ((a)>(b)?(a):(b))
T[1001][1001];U[1001][1001];H[1001];
backtrack(n,h){
	if(n==0)return;
	if(U[n][h]<0)backtrack(n-1,h+H[n-1]),putchar('D');
	else backtrack(n-1,h-H[n-1]),putchar('U');
}
main(t,N,i,j,a,b){for(scanf("%d",&t);t--;){
	for(scanf("%d",&N),i=0;i<N;i++)scanf("%d",H+i);
	memset(T,99,sizeof(T));T[0][0]=0;
	for(i=0;i<N;i++)for(j=0;j<1000;j++){
		a=j>=H[i]?max(T[i][j-H[i]],j):99999;
		b=T[i][j+H[i]];
		if(a<=b)T[i+1][j]=a,U[i+1][j]=1;
		else T[i+1][j]=b,U[i+1][j]=-1;
	}
	if(T[N][0]>=99999){puts("IMPOSSIBLE");continue;}
	backtrack(N,0);
	puts("");
}}