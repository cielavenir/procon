main(i,n,m,a,b,c){for(scanf("%d%d%d%d",&n,&m,&a,&b);i<=m;n-=c,i++){
	if(n<=a)n+=b;
	if(scanf("%d",&c),n<c)printf("%d\n",i),exit(0);
}puts("complete"),exit(0);}