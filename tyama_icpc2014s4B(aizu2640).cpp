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
	}
	void move(){
		int d_orig=(d+3)%4,i=0;
		for(;i<4;i++){
			d=(d_orig+i)%4;
			if(v[y+D[d][0]][x+D[d][1]]=='.')break;
		}
		y=y+D[d][0];
		x=x+D[d][1];
	}
};

int main(){
	int sx,sy,gx,gy,d;
	int N,M;
	cin>>N>>M;
	vector<string> m(N+2);
	m[0]=m[N+1]=string(M+2,'#');
	for(int i=1;i<=N;i++){
		string s;
		cin>>s;
		for(int j=0;j<M;j++){
			if(s[j]=='G')gx=j+1,gy=i,s[j]='.';
			if(s[j]=='>')sx=j+1,sy=i,d=0,s[j]='.';
			if(s[j]=='^')sx=j+1,sy=i,d=1,s[j]='.';
			if(s[j]=='<')sx=j+1,sy=i,d=2,s[j]='.';
			if(s[j]=='v')sx=j+1,sy=i,d=3,s[j]='.';
		}
		m[i]=string(1,'#')+s+'#';
	}
	Maze maze(sx,sy,d,m);
	set<pair<int,int> >se;
	se.insert(make_pair(sx,sy));
	for(int i=0;i<N*M*4;i++){
		maze.move();
		se.insert(make_pair(maze.x,maze.y));
		if(maze.x==gx&&maze.y==gy){
			cout<<se.size()<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}