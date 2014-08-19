#define M 9999
T[M]={1,1},S[M];main(i,j){
	for(i=2;i<M;i++)if(!T[i])for(j=i*2;j<M;j+=i)T[j]=1;
	for(i=2;i<M;i++)S[i]=S[i-1]+!T[i];
	for(;~scanf("%d,%d",&i,&j);)printf("%d\n",S[j]-S[i-1]);
}