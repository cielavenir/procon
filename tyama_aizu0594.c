#define max(a,b) ((a)>(b)?(a):(b))
r;main(i,N,X,Y,x,y){
	scanf("%d%d%d%d%d",&N,&N,&N,&X,&Y);
	for(;i<N;i++){
		scanf("%d%d",&x,&y);
		if((x-X)*(y-Y)>0)r+=max(abs(x-X),abs(y-Y));
		else r+=abs(x-X)+abs(y-Y);
		X=x,Y=y;
	}
	printf("%d\n",r);
}