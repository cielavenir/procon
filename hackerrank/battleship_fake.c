main(n,x,y){
	if(scanf("%d",&n)>0&&n){
		getchar();
		for(y=0;y<n;getchar(),y++)for(x=0;x<n;x++)if(getchar()=='-')printf("%d %d\n",y,x),exit(0);
	}else{
		puts("0 1");
		puts("7 5");
		puts("0 4:0 5");
		puts("2 5:2 6");
		puts("5 3:5 5");
		puts("8 1:8 4");
		puts("3 9:7 9");
	}
}