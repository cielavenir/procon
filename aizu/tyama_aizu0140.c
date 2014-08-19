main(n,a,b){for(scanf("%d",&n);n--;puts("")){
	scanf("%d%d",&a,&b);
	if(a<6&&b<6){
		if(a<b)for(;a<=b;a++){printf("%d",a);if(a!=b)putchar(' ');}
		else for(;a>=b;a--){printf("%d",a);if(a!=b)putchar(' ');}
	}else if(b<6){
		for(;a<10;a++){printf("%d",a);putchar(' ');}
		for(a=5;a>=b;a--){printf("%d",a);if(a!=b)putchar(' ');}
	}else if(a>5&&b<a){
		for(;a<10;a++){printf("%d",a);putchar(' ');}
		for(a=5;a>0;a--){printf("%d",a);if(a!=b)putchar(' ');}
		for(a=0;a<=b;a++){printf("%d",a);if(a!=b)putchar(' ');}
	}else{
		for(;a<=b;a++){printf("%d",a);if(a!=b)putchar(' ');}
	}
}exit(0);}