#define M 10000000
T[M+1];
main(i,j){
	for(i=2;i<=M;i++)T[i]=2;
	for(i=2;i<sqrt(M);i++)for(j=i*i,T[j]--;j<=M;j+=i)T[j]+=2;
	for(j=0,i=2;i<M;i++)j+=T[i]==T[i+1];
	printf("%d\n",j);
}