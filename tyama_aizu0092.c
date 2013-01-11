#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
char s[1001];D[2][1001];main(n,i,j,M){
	for(;scanf("%d",&n),n;printf("%d\n",M))
		for(memset(D,0,sizeof(D)),M=i=0;i<n;i++){
			scanf("%s",s);
			for(j=1;j<=n;j++)if(s[j-1]=='*')D[1][j]=-1;
			for(j=1;j<=n;j++)D[1][j]=D[1][j]!=-1?min(D[0][j-1],min(D[0][j],D[1][j-1]))+1:0,M=max(M,D[1][j]);
			memcpy(D[0],D[1],sizeof(D[1]));
			memset(D[1],0,sizeof(D[1]));
		}
exit(0);}