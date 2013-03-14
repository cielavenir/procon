a[301],n;main(i,j){
	for(a[0]=i=1;i<18;i++)for(j=i*i;j<=300;j++)a[j]+=a[j-i*i];
	for(;scanf("%d",&n),n;)printf("%d\n",a[n]);
exit(0);}