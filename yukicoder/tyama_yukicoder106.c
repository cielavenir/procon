#define M 2000000
t[M+1],n,k,i;main(j){
	scanf("%d%d",&n,&k);
	for(i=2;i<=M;i++)if(!t[i])for(j=i;j<=M;j+=i)t[j]++;
	for(j=i=0;i<=n;i++)j+=t[i]>=k;
	n=!printf("%d\n",j);
}