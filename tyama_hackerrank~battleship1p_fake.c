main(n,x,y){
	scanf("%d",&n);getchar();
	for(y=0;y<n;getchar(),y++)for(x=0;x<n;x++)if(getchar()=='-')printf("%d %d\n",y,x),exit(0);
}