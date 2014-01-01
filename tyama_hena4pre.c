// http://qiita.com/Nabetani/items/9c514267214d3917edf2
#include <stdio.h>
dx[]={-2,2,0,0},dy[]={0,0,-2,2},r;
int M[9][9];
D(x,y,d){
	int i=0;
	if(x==8&&y==8){r++;return;}
	for(;i<4;i++)if(0<=x+dx[i]&&x+dx[i]<=8 && 0<=y+dy[i]&&y+dy[i]<=8){
		if(!M[y+dy[i]][x+dx[i]]&&!M[y+dy[i]/2][x+dx[i]/2]){
			M[y+dy[i]][x+dx[i]]=1;
			D(x+dx[i],y+dy[i],d+1);
			M[y+dy[i]][x+dx[i]]=0;
		}
	}
}
main(){
	M[0][0]=1;
	D(0,0,0);
	printf("%d\n",r);
	fflush(stdout);
}