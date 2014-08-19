#define M 2000000
long long t[M+1];
main(){
	int i,j;
	for(i=2;i<=M;i++)if(!t[i])for(j=i*2;j<=M;j+=i)t[j]=1;
	for(i=2;i<=M;i++)t[i]=(t[i]?0:i)+t[i-1];
	for(scanf("%d",&j);j--;)scanf("%d",&i),printf("%lld\n",t[i]);
}