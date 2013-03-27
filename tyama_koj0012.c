#define M 10000000
T[M]={1,1};X[M+1];main(i,j){
	for(i=3;i<=M;i+=2)if(!T[i])for(X[i]=T[(i-1)/2]?0:i,j=i*2;j<=M;j+=i)T[j]=1;
	for(i=0;++i<=M;)if(!X[i])X[i]=X[i-1];
	for(;~scanf("%d",&i);)printf("%d\n",X[i]);
}