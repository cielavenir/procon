main(i,N,T,E,x,y){
	for(scanf("%d%d%d",&N,&T,&E),i=1;i<=N;i++){
		for(scanf("%d",&x),y=0;y<T-E;y+=x);
		if(y<=T+E){printf("%d\n",i);break;}
	}
	if(i>N)puts("-1");
	exit(0);
}