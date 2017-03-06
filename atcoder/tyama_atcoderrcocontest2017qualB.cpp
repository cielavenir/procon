#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cstdio>
using namespace std;
const int D[4][2]={ //Right,Up,Left,Down
	{0,1},
	{-1,0},
	{0,-1},
	{1,0},
};
const char *T="RULD";
class Maze{
	vector<vector<int>> &v;
public:
	int x,y,d,z,threshold;
	Maze(int _x,int _y,int _d,vector<vector<int>>&_v)
		: x(_x),y(_y),d(_d),v(_v),threshold(0),z(1){}
	int move(){
		v[y][x]=threshold+1;
		int d_orig=(d+3)%4,i=0;
		for(;i<4;i++){
			d=(d_orig+i*z+4)%4;
			if(
				0<=y+D[d][0]&&y+D[d][0]<v.size() &&
				0<=x+D[d][1]&&x+D[d][1]<v[0].size() &&
				v[y+D[d][0]][x+D[d][1]]!=-1 &&
				v[y+D[d][0]][x+D[d][1]]<=threshold
			)break;
		}
		if(i==4){
			d=d_orig;
			return -1;
		}
		y=y+D[d][0];
		x=x+D[d][1];
		//printf("%d %d %d %d\n",x,y,d,threshold);
		return d;
	}
};
int main(){
	//vector<vector<pair<int,int>>>r;
	int H,W,K,sr,sc,N;
	cin>>H>>W>>K>>sr>>sc;
	sr--,sc--;
	vector<vector<int>>v;
	for(int h=0;h<H;h++){
		string s;
		cin>>s;
		vector<int>w;
		for(auto &e:s)w.push_back(e=='#' ? -1 : 0);
		v.push_back(w);
	}
	cin>>N;
	vector<tuple<int,int,int,int>>Z(N);
	for(int n=0;n<N;n++){
		cin>>get<0>(Z[n])>>get<1>(Z[n])>>get<2>(Z[n])>>get<3>(Z[n]);
	}
	Maze maze(sc,sr,0,v);
	int cnt=0;
	for(int cnt=0;cnt<2500;cnt++){
		int d=maze.move();
		if(d<0){
			maze.threshold++;
			maze.z*=-1;
			d=maze.move();
			//cout<<string(2500-cnt,'-');
		}
		cout<<T[d];
	}
	cout<<endl;
	return 0;
}
