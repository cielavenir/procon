a[1000];
main(){
	int I,D,N,i,r,x;
	for(;~scanf("%d%d%d",&I,&D,&N);){
		I-=12;
		for(i=0;i<N;i++)scanf("%d",a+i+1),a[i+1]-=6;
		a[N+1]=I+D;
		a[0]=-D;
		for(r=i=0;i<N+1;i++)x=(a[i+1]-a[i])/D-1,x=x<0?0:x,r+=x;
		printf("%d\n",r);
	}
}