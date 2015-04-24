#include <vector>
#include <cstdio>
using namespace std;
const int D[4][2]={
	{1,0},{0,1},{-1,0},{0,-1}
};
int main(){
	int H,W,d=0,x=0,y=0;
	scanf("%d%d",&H,&W);
	vector<vector<char> >v(H);
	for(int i=0;i<H;i++)v[i].resize(W);
	v[0][0]='A';
	for(int i=1;i<H*W;i++){
		int nx,ny;
		for(;;d=(d+1)%4){
			nx=x+D[d][0],ny=y+D[d][1];
			if(0<=nx&&nx<W && 0<=ny&&ny<H && !v[ny][nx]){
				x=nx,y=ny,v[y][x]='A'+(i%26);
				break;
			}
		}
	}
	for(int i=0;i<H;puts(""),i++)for(int j=0;j<W;j++)printf("   %c",v[i][j]);
}