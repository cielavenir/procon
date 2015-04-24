#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{0,-1},
	{-1,0},
	{0,1},
	{1,0},
};
int main(){
	int H,W,path=0;
	cin>>H>>W;
	vector<string>v(H);
	for(int i=0;i<H;i++){
		cin>>v[i];
		for(int j=0;j<W;j++)path+=v[i][j]=='.';
	}
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(v[i][j]=='.'){
		for(int _d=0;_d<4;_d++){
			int x=j,y=i,p=0;
			for(int d=_d,fail=0;fail<2&&p<path;){
				int nx=x+D[d].x,ny=y+D[d].y;
				if(0<=nx&&nx<W && 0<=ny&&ny<H && v[ny][nx]=='.'){
					x=nx,y=ny;
					fail=0,p++;
					if(x==j&&y==i)break;
				}else{
					fail++,d=(d+1)%4;
				}
			}
			if(p==path&&x==j&&y==i){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
}