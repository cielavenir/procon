#define M 10000000
char T[M+1];
main(i,j){
	for(i=2;i<=M;i++)
		if(!T[i])
			for(j=i*2;j<=M;j+=i)T[j]=1;
	for(;scanf("%d",&i),i;printf("%d\n",i))
		for(i-=i%2?0:1;T[i]||T[i-2]||T[i-6]||T[i-8];i-=2);
	exit(0);
}