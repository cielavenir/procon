//based on KOJ0011
long long m[1001][1001];main(i,a,b,q,x,y,X,Y){
	long long j,k;
	for(;~scanf("%d",&a);printf("%lld\n",j)){
		b=a;
		for(j=1;j<=a;j++)for(i=1;i<=b;i++)scanf("%lld",m[j]+i);
		for(j=1;j<=a;j++)for(i=1;i<=b;i++)m[j][i]+=m[j-1][i];
		for(j=1;j<=a;j++)for(i=1;i<=b;i++)m[j][i]+=m[j][i-1];
		//for(j=i=0;i<q;i++)scanf("%d%d%d%d",&y,&x,&Y,&X),j+=m[Y][X]-m[y-1][X]-m[Y][x-1]+m[y-1][x-1];
		j=-999999999;
		for(X=1;X<=a;X++)for(Y=1;Y<=a;Y++)for(x=0;x<X;x++)for(y=0;y<Y;y++){
			k=m[Y][X]-m[y][X]-m[Y][x]+m[y][x];
			if(j<k)j=k;
		}
	}
}