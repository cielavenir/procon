z[999][999],d[999],n,m,a,b,i;
int D(c){
	if(d[c]>=0)return d[c];
	int i=0,x=0,y;
	for(;i<n;i++)if(z[i][c]){
		y=D(i)+z[i][c];
		if(x<y)x=y;
	}
	return d[c]=x;
}
main(x){
	for(scanf("%d%d",&n,&m);i<m;i++)scanf("%d%d%d",&a,&b,&x),z[a][b]=x;
	for(i=1;i<n;i++)d[i]=-1;
	printf("%d\n",D(n-1));exit(0);
}