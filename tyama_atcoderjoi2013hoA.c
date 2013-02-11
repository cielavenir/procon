a,b,c,d,s,x,y;main(n){
	for(scanf("%d",&n);d<n;){
		scanf("%d",&x);
		if(x==y)a=b,b=c,c=d;
		else y=x;
		d++;
		if(s<d-a)s=d-a; //終端-3つ前の終端
	}
	printf("%d\n",s);
exit(0);}