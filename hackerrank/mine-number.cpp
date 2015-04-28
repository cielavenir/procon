#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{-1,-1},
	{-1,0},
	{-1,1},
	{0,-1},
	{0,1},
	{1,-1},
	{1,0},
	{1,1},
};
int main(){
	int H,W;
	cin>>H>>W;
	vector<string>v(H);
	for(int h=0;h<H;h++)cin>>v[h];
	for(int h=0;h<H;h++)for(int w=0;w<W;w++)if(v[h][w]!='#'){
		int s=0;
		for(auto &d:D){
			int x=w+d.x,y=h+d.y;
			if(0<=x&&x<W && 0<=y&&y<H && v[y][x]=='#')s++;
		}
		if(s)v[h][w]='0'+s;
	}
	for(int h=0;h<H;h++)cout<<v[h]<<endl;
}