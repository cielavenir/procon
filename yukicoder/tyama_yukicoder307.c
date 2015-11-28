#include <stdio.h>
int a[200][200],H,W,Q,R,C,X,Z=-1,h,w;
int dfs(int x,int y,int c){
	if(x<0||W<=x || y<0||H<=y || a[y][x]==c)return 0;
	a[y][x]=c;
	return 1+dfs(x-1,y,c)+dfs(x+1,y,c)+dfs(x,y-1,c)+dfs(x,y+1,c);
}
int main(){
	for(scanf("%d%d",&H,&W);h<H;h++)for(w=0;w<W;w++)scanf("%d",&a[h][w]);
	for(scanf("%d",&Q);Q;Q--){
		scanf("%d%d%d",&R,&C,&X);R--,C--;
		if(dfs(C,R,X)==H*W)break;
	}
	for(;Q--;)scanf("%d%d%d",&R,&C,&Z);
	for(h=0;h<H;h++)for(w=0;w<W;w++)printf(w<W-1?"%d ":"%d\n",Z<0?a[h][w]:Z);
}