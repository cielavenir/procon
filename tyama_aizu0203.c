M[15][15],C[15][15],X,Y;
int D(x,y){
	if(y>=Y-1)return 1;
	if(M[x][y])return M[x][y];
	if(C[x][y]==2)return M[x][y]=y+2>=Y||C[x][y+2]!=1?D(x,y+2):0;
	int s=0;
	if(0<x&&C[x-1][y+1]==0)s+=D(x-1,y+1);
	if(C[x][y+1]!=1)s+=D(x,y+1);
	if(x<X-1&&C[x+1][y+1]==0)s+=D(x+1,y+1);
	return M[x][y]=s;
}
main(i,j,s){for(;scanf("%d%d",&X,&Y),X;printf("%d\n",j)){
memset(M,0,sizeof(M));
for(j=0;j<Y;j++)for(i=0;i<X;i++)scanf("%d",C[i]+j);
for(j=i=0;i<X;i++)if(C[i][0]!=1)j+=D(i,0);
}exit(0);}