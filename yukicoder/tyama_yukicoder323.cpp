#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{0,-1},{0,1},{-1,0},{1,0}
};

int main(){
	int H,W,A,Sx,Sy,B,Gx,Gy;
	cin>>H>>W>>A>>Sy>>Sx>>B>>Gy>>Gx;
	vector<string>v(H);
	for(int i=0;i<H;i++)cin>>v[i];
	queue<tuple<int,int,int>>q;
	q.emplace(Sx,Sy,A);
	map<tuple<int,int,int>,int>depth={ {make_tuple(Sx,Sy,A),0} };
	for(;!q.empty();){
		auto cur=q.front();q.pop();
		int cx=get<0>(cur),cy=get<1>(cur),cw=get<2>(cur);
		for(auto &d:D){
			if(0<=cx+d.x&&cx+d.x<W && 0<=cy+d.y&&cy+d.y<H){
				int w=cw+(v[cy+d.y][cx+d.x]=='*' ? 1 : -1);
				if(1<=w && w<=max(A,B)+H+W){
					if(cx+d.x==Gx && cy+d.y==Gy && w==B){
						cout<<"Yes"<<endl;
						return 0;
					}
					auto nxt=make_tuple(cx+d.x,cy+d.y,w);
					if(depth.find(nxt)==depth.end()){
						q.push(nxt);
						depth[nxt]=depth[cur]+1;
					}
				}
			}
		}
	}
	cout<<"No"<<endl;
}