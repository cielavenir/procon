int M[99][99];
main(n,i,x,y){
	for(;scanf("%d",&n),n;){
		memset(M,0,sizeof(M));
		x=n/2,y=n/2+1,M[x][y]=1;
		for(i=2;i<=n*n;i++){
			x=(x+1)%n,y=(y+1)%n;
			for(;M[x][y];y=(y+1)%n)x=(x+n-1)%n;
			M[x][y]=i;
		}
		for(y=0;y<n;y++,puts(""))
			for(x=0;x<n;x++)printf("%4d",M[x][y]);
	}
exit(0);}