a[1001];main(n,m,x,y){
	for(scanf("%d%d",&n,&m);m--;)scanf("%d%d",&x,&y),a[x]++,a[y]++;
	for(x=1;x<=n;x++)printf(x<n?"%d ":"%d\n",a[x]);
}