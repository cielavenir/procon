#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
	}
	bool move(){
		int d_orig=(d+3)%4,i=0;
		for(;i<4;i++){
			d=(d_orig+i)%4;
			if(v[y+D[d][0]][x+D[d][1]]=='.')break;
		}
		if(i==4)return false;
		y=y+D[d][0];
		x=x+D[d][1];
		return true;
	}
};

int main(){
	int sx,sy,gx,gy,d;
	int N,M;
	for(;cin>>N>>M&&N&&M;){
		vector<string> m(N+2);
		vector<vector<int> >z(N);
		m[0]=m[N+1]=string(M+2,'#');
		for(int i=1;i<=N;i++){
			string s;
			cin>>s;
			m[i]=string(1,'#')+s+'#';
			z[i-1].resize(M);
			fill(z[i-1].begin(),z[i-1].end(),-1);
		}
		Maze maze(1,1,3,m);
		int r=0;
		do{
			if(maze.y*maze.x>1){
				//m[maze.y][maze.x]='#';
				if(z[maze.y-1][maze.x-1]<0)z[maze.y-1][maze.x-1]=r;
				else if(z[maze.y-1][maze.x-1]!=r)break;
			}

			if(maze.x==1&&maze.y==N)r++;
			if(maze.x==M&&maze.y==N)r++;
			if(maze.x==M&&maze.y==1)r++;
		}while(maze.move()&&(maze.x!=1||maze.y!=1));
		cout<<(r==3&&maze.x==1&&maze.y==1 ? "YES" : "NO")<<endl;
	}
}
