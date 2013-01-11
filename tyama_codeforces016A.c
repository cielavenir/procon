char a[100][101];
main(n,m,i,j,b){
	for(scanf("%d%d",&n,&m),i=0;i<n;i++)scanf("%s",a[i]);
	for(b=i=0;i<n;b=a[i][0],i++){
		if(b==a[i][0])goto z;
		for(j=1;j<m;j++)
			if(a[i][0]!=a[i][j]){
				z:puts("NO"),exit(0);
			}
	}
	puts("YES");
}