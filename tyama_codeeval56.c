dx[]={-1,1,0,0},dy[]={0,0,-1,1},r;
int M[4][4];
D(x,y,d){
	int i=0;
	if(x==3&&y==3){r++;return;}
	for(;i<4;i++)if(0<=x+dx[i]&&x+dx[i]<4 && 0<=y+dy[i]&&y+dy[i]<4){
		if(!M[y+dy[i]][x+dx[i]]){
			M[y+dy[i]][x+dx[i]]=1;
			D(x+dx[i],y+dy[i],d+1);
			M[y+dy[i]][x+dx[i]]=0;
		}
	}
}
main(i,j){
	j=i=0;
	//for(j=0;j<3;j++)for(i=0;i<4;i++){
		M[j][i]=1;
		D(i,j,0);
		M[j][i]=0;
	//}
	printf("%d\n",r);
}