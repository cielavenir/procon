z[110][110],Z[110][110],w,h;
D(x,y){Z[x][y]=1;if(x>0&&z[x][y]>z[x-1][y])D(x-1,y);if(y>0&&z[x][y]>z[x][y-1])D(x,y-1);if(x<w&&z[x][y]>z[x+1][y])D(x+1,y);if(y<h&&z[x][y]>z[x][y+1])D(x,y+1);}
main(p,x,y,n){for(;scanf("%d%d%d",&w,&h,&p),w;printf("%d\n",p)){
	memset(Z,0,sizeof(Z));
	for(y=0;y<h;y++)for(x=0;x<w;x++)scanf("%d",z[x]+y);
	for(;p;p--)scanf("%d%d",&x,&y),D(x,y);
	for(y=0;y<h;y++)for(x=0;x<w;x++)p+=Z[x][y];
}exit(0);}