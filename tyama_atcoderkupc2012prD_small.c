main(N,a,b,c){
	scanf("%d%d%d%d",&N,&a,&b,&c);
	if(N>1)exit(1);
	puts(a*b==c?"YES":"NO");
	exit(0);
}