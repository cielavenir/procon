#define M 1000000
int t[M+1];
main(){
	int i,j,q;
	for(i=2;i<=M;i++)if(!t[i])for(j=i*2;j<=M;j+=i)t[j]=1;
	for(i=2;i<=M;i++)t[i]=t[i-1]+(t[i]^1);
	for(scanf("%d",&q);q--;){
		scanf("%d%d",&i,&j);
		printf("%d\n",t[j]-t[i-1]);
	}
	exit(0);
}