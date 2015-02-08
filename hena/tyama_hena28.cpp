// http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
// http://nabetani.sakura.ne.jp/hena/ord28spirwa/

#include <cstdio>
#include <string>
#include <vector>
using namespace std;
const int D[4][2]={ //Right,Up,Left,Down
	{0,1},
	{-1,0},
	{0,-1},
	{1,0},
};

class Maze{
	vector<string> &v;
	int x,y,d;
public:
	Maze(int _x,int _y,int _d,vector<string>&_v)
		: x(_x),y(_y),d(_d),v(_v){
			v[y][x]='*';
	}
	void move(){
		int d_orig=(d+3)%4,i=0;
		for(;i<4;i++){
			d=(d_orig+i)%4;
			if(v[y+D[d][0]][x+D[d][1]]=='.')break;
		}
		y=y+D[d][0];
		x=x+D[d][1];
		v[y][x]='*';
	}
	int dir(){return d;}
};

int main(){
	const string dir="ENWS";
	const int Z=100;
	int n,e,s,w;
	long long days;
	for(;scanf("%d,%d,%d,%d:%lld",&n,&e,&s,&w,&days);){
		vector<string> m(Z*2);
		for(int i=0;i<Z*2;i++)m[i]=string(Z*2,'.');
		m[Z][Z]='*';
		for(int i=0;i<n;i++)m[Z-i-1][Z]='*';
		for(int i=0;i<e;i++)m[Z][Z+i+1]='*';
		for(int i=0;i<s;i++)m[Z+i+1][Z]='*';
		for(int i=0;i<w;i++)m[Z][Z-i-1]='*';
		Maze maze(Z+1,Z-1,0,m);
		for(int i=0;i<=days;i++)maze.move();
		printf("%c\n",dir[maze.dir()]);
		fflush(stdout);
	}
}