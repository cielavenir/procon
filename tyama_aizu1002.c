cnt[9999];
main(T,N,i,j,r,p,f){for(scanf("%d",&T);T--;printf("%d\n",r-f-!p)){
	memset(cnt,0,sizeof(cnt));
	scanf("%d",&N),getchar();
	for(i=0;i<2*N;i++)if(getchar()=='Y')cnt[(i+1)/2]|=1;
	for(i=0;i<2*N;i++)if(getchar()=='Y')cnt[(i+1)/2]|=2;
	for(r=p=f=i=0;!p&&i<N+1;i++,r++)
		if(cnt[i]&2)r+=2,p=1,f=0;
		else if(cnt[i]&1)r+=1,p=1,f=1;
	for(;i<N+1;i++,r++)
		if(cnt[i]==3)r+=2,f=1;
		else if(cnt[i])r+=1,f=cnt[i]&1;
}exit(0);}