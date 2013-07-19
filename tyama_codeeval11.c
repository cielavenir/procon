main(x,y,r){for(;~scanf("%d%d",&x,&y);printf("%d\n",r)){
	if(x==29)x=10;
	if(y==29)y=10;
	if(x==10&&y==10){r=20;continue;}
	if(x==3||x==10)x=20;
	if(y==3||y==10)y=20;
	if(x==20&&y==20)r=8;else r=30;
}}