#define X(V,N)0<=V+D[d][N]*(m-1)&&V+D[d][N]*(m-1)<n
D[13][3]={{1,0,0},{0,1,0},{0,0,1},{1,1,0},{1,0,1},{0,1,1},{1,-1,0},{1,0,-1},{0,1,-1},{1,1,1},{-1,1,1},{1,-1,1},{1,1,-1}};
M[7][7][7];main(n,m,p,I,x,y,i,j,k,c,d,z){for(;scanf("%d%d%d",&n,&m,&p),n;){
	for(memset(M,0,sizeof(M)),c=1,I=0;I<p;c*=-1){
		scanf("%d%d",&x,&y),x--,y--,I++;
		for(i=0;;i++)if(!M[x][y][i]){M[x][y][i]=c;break;}
		for(i=0;i<n;i++)for(j=0;j<n;j++)for(k=0;k<n;k++)for(d=0;d<13;d++)if(X(i,0)&&X(j,1)&&X(k,2)){
			for(z=0;z<m;z++)if(M[i+D[d][0]*z][j+D[d][1]*z][k+D[d][2]*z]!=c)break;
			if(z==m){printf("%s %d\n",c==1?"Black":"White",I);goto next;}
		}
	}
	puts("Draw");
next:
	for(;I<p;I++)scanf("%d%d",&x,&y);
}exit(0);}