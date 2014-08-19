m[101][101];main(i,j,x,y){for(;scanf("%d%d",&y,&x),x;){
	for(getchar(),j=0;j<y;getchar(),j++)for(i=0;i<x;i++)m[i][j]=getchar();
	for(x=y=i=0;i<999;i++)if(m[x][y]=='>')x++;else if(m[x][y]=='<')x--;else if(m[x][y]=='v')y++;else if(m[x][y]=='^')y--;else break;
	if(i==999)puts("LOOP");else printf("%d %d\n",x,y);
}exit(0);}