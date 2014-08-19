int x[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
main(m,d,M,D,i,r){
	scanf("%d%d%d%d",&m,&d,&M,&D);
	if(m==M)r=D-d;
	else{
		r=x[m]-d;
		for(i=m+1;i<M;i++)r+=x[i];
		r+=D;
	}
	printf("%d\n",r);exit(0);
}