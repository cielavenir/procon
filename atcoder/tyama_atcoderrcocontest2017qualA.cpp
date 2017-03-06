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
	int d,threshold;
public:
	int x,y;
	Maze(int _x,int _y,int _d,int _threshold,vector<string>&_v)
		: x(_x),y(_y),d(_d),v(_v),threshold(_threshold){}
	int move(){
		int d_orig=(d+3)%4,i=0;
		for(;i<4;i++){
			d=(d_orig+i)%4;
			if(
				0<=y+D[d][0]&&y+D[d][0]<v.size() &&
				0<=x+D[d][1]&&x+D[d][1]<v[0].size() &&
				v[y+D[d][0]][x+D[d][1]]>=threshold
			)break;
		}
		if(i==4)return -1;
		y=y+D[d][0];
		x=x+D[d][1];
		//printf("%d %d %d\n",x,y,d);
		return d;
	}
};
int main(){
	vector<set<pair<int,int>>>r;
	int H,W,K;
	cin>>H>>W>>K;
	vector<string>v(H);
	for(int h=0;h<H;h++){
		cin>>v[h];
	}
	for(int threshold:{'9','8','7','6','5','4','3','2','1'}){
		int h,w;
		//for(h=0;h<H;h++)for(w=0;w<W;w++)
		//for(h=H-1;h>=0;h--)for(w=W-1;w>=0;w--)
		for(h=0;h<H;h++)for(w=W-1;w>=0;w--)if(v[h][w]>=threshold){
			Maze maze(w,h,0,threshold,v);
			set<pair<int,int>> q={{h,w}};
			int c=0;
			for(;c<K*K;c++){
				int d=maze.move();
				if(d<0)break;
				q.emplace(maze.y,maze.x);
				if(q.size()==8){
					for(auto &f:q)v[f.first][f.second]='0';
					r.push_back(q);
					//q.clear();
					break;
				}
			}
		}
	}
	cout<<r.size()<<endl;
	for(auto &e:r){
		for(auto &f:e){
			cout<<(f.first+1)<<' '<<(f.second+1)<<endl;
		}
	}
}
