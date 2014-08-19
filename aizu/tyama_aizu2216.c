main(s,i,j,k){
	for(;scanf("%d%d",&i,&s),s;printf("%d %d %d\n",i,j,k)){
		for(s-=i,k=0;s>=1000;k++)s-=1000;
		for(j=0;s>=500;j++)s-=500;
		for(i=0;s>=100;i++)s-=100;
	}
	return 0;
}