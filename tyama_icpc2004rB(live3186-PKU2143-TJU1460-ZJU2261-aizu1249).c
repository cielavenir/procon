D[13][3]={{1,0,0},{0,1,0},{0,0,1},{1,1,0},{1,0,1},{0,1,1},{1,-1,0},{1,0,-1},{0,1,-1},{1,1,1},{-1,1,1},{1,-1,1},{1,1,-1}};
M[9][9][9],q[2];main(n,m,p,I,x,y,z,j,c,d){for(;scanf("%d%d%d",&n,&m,&p),n;){
	for(memset(M,I=0,sizeof(M)),c=1;I++<p;c*=-1){
		for(scanf("%d%d",&x,&y),z=1;;z++)if(!M[x][y][z]){M[x][y][z]=c;break;}
		for(d=0;d<13;d++){
			for(j=0;j<2;j++)for(q[j]=0;M[x+D[d][0]*q[j]][y+D[d][1]*q[j]][z+D[d][2]*q[j]]==c;q[j]+=2*j-1);
			if(q[1]-q[0]-1>=m){printf(c==1?"Black %d\n":"White %d\n",I);goto next;}
		}
	}
	puts("Draw");
next:
	for(;I++<p;)scanf("%d%d",&x,&y);
}exit(0);}