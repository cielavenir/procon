main(y,m,d,v){
	for(;~scanf("%d%d%d",&y,&m,&d);){
		v=y*416+m*32+d;
		if(v<777384)puts("pre-meiji");
		else if(v<795646)printf("meiji %d %d %d\n",y-1867,m,d);
		else if(v<801625)printf("taisho %d %d %d\n",y-1911,m,d);
		else if(v<827464)printf("showa %d %d %d\n",y-1925,m,d);
		else printf("heisei %d %d %d\n",y-1988,m,d);
	}exit(0);
}