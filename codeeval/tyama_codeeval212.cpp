#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
const int D[4][2]={ //Right,Up,Left,Down
	{0,1},
	{-1,0},
	{0,-1},
	{1,0},
};

class Maze{
	vector<string> &v;
public:
	int x,y,d;
	Maze(int _x,int _y,int _d,vector<string>&_v)
		: x(_x),y(_y),d(_d),v(_v){
			v[y][x]='#';
	}
	void move(){
		int d_orig=(d+3)%4,i=0;
		for(;i<4;i++){
			d=(d_orig+i)%4;
			if(v[y+D[d][0]][x+D[d][1]]=='.')break;
		}
		y=y+D[d][0];
		x=x+D[d][1];
		v[y][x]='#';
	}
};

int main(){
	int W,H,X,Y;
	for(;~scanf("%dx%d | %d %d",&W,&H,&X,&Y);){
		vector<string> m(H+2);
		m[0]=m[H+1]=string(W+2,'#');
		for(int i=1;i<=H;i++)m[i]=string(1,'#')+string(W,'.')+'#';
		Maze maze(1,H,0,m);
		for(int r=1;;r++){
			if(maze.x==X&&maze.y==Y){
				printf("%d\n",r);
				break;
			}
			maze.move();
		}
	}
}