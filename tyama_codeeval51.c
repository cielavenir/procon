x[99],y[99];
main(n,i,j){
	for(;scanf("%d",&n),n;){
		double R=1e8,r;
		for(i=0;i<n;i++)scanf("%d%d",x+i,y+i);
		for(i=0;i<n-1;i++)for(j=i+1;j<n;j++)if(R>(r=hypot(x[i]-x[j],y[i]-y[j])))R=r;
		printf(R<10000?"%.4f\n":"INFINITY\n",R);
	}
}