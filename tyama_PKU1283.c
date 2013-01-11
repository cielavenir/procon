long long T[201][201];
main(n,k){
	for(n=1;n<201;n++)T[n][n]=T[n][1]=1;
	for(k=2;k<201;k++)
		for(n=k;n<201;n++)
			T[n][k]=T[n-1][k-1]+T[n-k][k];
	for(;scanf("%d%d",&n,&k),n;printf("%lld\n",T[n][k]));
}