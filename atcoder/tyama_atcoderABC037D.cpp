#include <vector>
#include <cstdio>
using namespace std;
 
typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{0,-1},{0,1},{-1,0},{1,0}
};
 
long long MOD=1000000007;
vector<long long>memo;
vector<vector<int>>M;
int H,W;
 
long long dfs(int x,int y){
	int key=x*H+y;
	if(memo[key])return memo[key];
	long long r=1;
	for(auto &d:D){
		int nx=x+d.x;
		int ny=y+d.y;
		if(0<=nx&&nx<W && 0<=ny&&ny<H && M[y][x]<M[ny][nx]){
			r=(r+dfs(nx,ny))%MOD;
		}
	}
	return memo[key]=r;
}
int main(){
	scanf("%d%d",&H,&W);
	M.resize(H);
	memo.resize(H*W);
	for(int y=0;y<H;y++){
		M[y].resize(W);
		for(int x=0;x<W;x++)scanf("%d",&M[y][x]);
	}
	long long r=0;
	for(int y=0;y<H;y++){
		for(int x=0;x<W;x++){
			r=(r+dfs((x+W/2)%W,(y+H/2)%H))%MOD;
		}
	}
	printf("%lld\n",r);
}