D[4][2]={/*{-1,-1},{-1,0},{-1,1},{0,-1},*/{0,1},{1,-1},{1,0},{1,1}};
char m[10][10];
int grid(){
	int i=1,j,k,l;
	for(;i<9;i++)for(j=1;j<9;j++)if(m[i][j]=='Q')for(k=0;k<4;k++)for(l=1;m[i+D[k][0]*l][j+D[k][1]*l];l++)if(m[i+D[k][0]*l][j+D[k][1]*l]=='Q')return 0;
	return 1;
}
void dfs(int depth){
	if(!grid())return;
	int i=1,j;
	if(depth==8){for(;i<9;i++)puts(m[i]+1);exit(0);}
	for(;i<9;i++)for(j=1;j<9;j++)if(m[i][j]!='Q'){
		m[i][j]='Q';
		dfs(depth+1);
		m[i][j]='.';
	}
}
main(i){
	for(;i<9;i++)scanf("%s",m[i]+1);
	dfs(3);
	puts("No Answer");
	exit(0);
}