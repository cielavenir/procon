int a[1000],n,m,i,j;
main(){for(;~scanf("%d%d",&n,&m);memset(a,0,sizeof(a))){
	for(i=1;i<m;i++){
		for(j=2;j<=n;j+=2)a[j]=1;
		for(j=3;j<=n;j+=3)a[j]^=1;
	}
	a[n]^=1;
	for(j=0,i=1;i<=n;i++)j+=a[i]^=1;
	printf("%d\n",j);
}}