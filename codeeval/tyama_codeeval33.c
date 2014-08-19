main(){
	int T,t=0,n,i,r,x,y;
	for(scanf("%d",&T);t<T;t++){
		scanf("%d",&n);
		for(r=i=0;n/2>i*i;i++){
			x=n-i*i;
			y=sqrt(x);
			r+=y*y==x;
		}
		printf("%d\n",r);
	}
}