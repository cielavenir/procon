v[4]={10,50,100,500},a[4],r[4];main(N,c,m,i){
	for(N=0;scanf("%d",&c),c;N++){
		if(N)puts("");
		scanf("%d%d%d%d",a,a+1,a+2,a+3);
		for(m=i=0;i<4;i++)m+=a[i]*v[i];
		m-=c;
		r[3]=m/500,r[2]=m%500/100,r[1]=m%100/50,r[0]=m%50/10;
		for(i=0;i<4;i++)if((a[i]-=r[i])>0)printf("%d %d\n",v[i],a[i]);
	}
	return 0;
}