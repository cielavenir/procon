#define M 999999
P[M],N[M];main(i,j,k,r,n,p,m){
	for(P[0]=P[1]=1,i=2;i<M;i++)if(!P[i])for(j=i*2;j<M;j+=i)P[j]=1;
	for(i=1;i<M;i++)N[i]=N[i-1]+!P[i];
	for(;scanf("%d",&n),n;printf("%d\n",r))
		for(r=-n,i=0;i<n;i++){
			scanf("%d%d",&p,&m);
			j=p-m-1;if(j<0)j=0;
			k=p+m;if(k>=M)k=M-1;
			r+=N[k]-N[j];
		}
}