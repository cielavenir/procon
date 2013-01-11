main(T,L,n,x,y,m,M){
	for(scanf("%d",&T);T;printf("%d %d\n",m,M),T--){
		for(m=M=0,scanf("%d%d",&L,&n);n;n--){
			scanf("%d",&x);
			if(x>L-x)y=L-x;else y=x,x=L-y;
			if(m<y)m=y;
			if(M<x)M=x;
		}
	}
}