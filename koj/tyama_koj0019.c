long long m[1001][1001];main(i,a,b,q,x,y,X,Y){
	long long j;
	for(;~scanf("%d%d%d",&a,&b,&q);printf("%lld\n",j)){
		for(j=1;j<=a;j++)for(i=1;i<=b;i++)scanf("%lld",m[j]+i);
		for(j=1;j<=a;j++)for(i=1;i<=b;i++)m[j][i]+=m[j-1][i];
		for(j=1;j<=a;j++)for(i=1;i<=b;i++)m[j][i]+=m[j][i-1];
		for(j=i=0;i<q;i++)scanf("%d%d%d%d",&y,&x,&Y,&X),j+=m[Y][X]-m[y-1][X]-m[Y][x-1]+m[y-1][x-1];
	}
	exit(0);
}