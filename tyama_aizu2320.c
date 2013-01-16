X[]={0,1,0,-1},Y[]={-1,0,1,0},f[109][109],g[109][109][4];char s[109],*D="NESW";
main(h,w,z,x,y,c,i,j,k){long long l;for(;scanf("%d%d%lld",&h,&w,&l),h;printf("%d %d %c\n",y,x,D[z])){
	memset(f,1,sizeof(f)),memset(g,0,sizeof(g));
	for(i=0;i<h;i++)for(scanf("%s",s),j=0;j<w;j++){
		for(k=0;k<4;k++)if(s[j]==D[k])x=j+1,y=i+1,z=k;
		if(s[j]!='#')f[i+1][j+1]=0;
	}
	for(c=0;l;l--,c++){
		if(g[y][x][z]&&(l%=c-g[y][x][z])==0)break;
		for(g[y][x][z]=c;f[y+Y[z]][x+X[z]];z=(z+1)%4);
		x+=X[z],y+=Y[z];
	}
}exit(0);}