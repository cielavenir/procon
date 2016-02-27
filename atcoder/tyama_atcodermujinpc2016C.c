p[99],x[199],y[199],r,N,M,i,a,b;
R(a){return p[a]-a?(p[a]=R(p[a])):a;}
main(j){
	scanf("%d%d",&N,&M);
	for(i=0;i<M;i++)scanf("%d%d",x+i,y+i),x[i]--,y[i]--;
	for(i=0;i<1<<~-N;i++){
		for(j=0;j<N;j++)p[j]=j;
		for(j=0;j<M;j++)if(((i>>x[j])&1)^((i>>y[j])&1))a=R(x[j]),b=R(y[j]),p[a]=b;
		for(j=0;j<N;j++)if(R(0)!=R(j))break;
		if(j==N)r++;
	}
	r=!printf("%d\n",r);
}