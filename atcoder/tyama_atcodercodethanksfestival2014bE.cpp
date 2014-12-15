#include <queue>
#include <map>
#include <cstdio>
using namespace std;
typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{0,1},
	{1,0},
	{0,-1},
	{-1,0},
};

int main(){
	int R,C,N;
	pair<int,int>start,goal;
	scanf("%d%d%d%d%d%d%d",&R,&C,&start.second,&start.first,&goal.second,&goal.first,&N);
	start.first--;
	start.second--;
	goal.first--;
	goal.second--;
	vector<vector<int> >v(R);
	for(int i=0;i<R;i++)v[i].resize(C);
	for(int i=0;i<N;i++){
		int r,c,h,w;
		scanf("%d%d%d%d",&r,&c,&h,&w);
		r--;c--;
		for(int y=0;y<h;y++)for(int x=0;x<w;x++)v[y+r][x+c]=1;
	}
	if(!v[start.second][start.first]){
		puts("NO");
		return 0;
	}
	queue<pair<int,int>>q;
	q.push(start);
	map<pair<int,int>,pair<int,int>>back;
	back[start]=start;
	for(;!q.empty();){
		pair<int,int> cur=q.front();q.pop();
		for(auto &d:D){
			if(
				0<=cur.first+d.x&&cur.first+d.x<v[0].size() &&
				0<=cur.second+d.y&&cur.second+d.y<v.size() &&
				v[cur.second+d.y][cur.first+d.x] &&
				back.find({cur.first+d.x,cur.second+d.y})==back.end()
			){
				q.push({cur.first+d.x,cur.second+d.y});
				back[{cur.first+d.x,cur.second+d.y}]=cur;
				if(back.find(goal)!=back.end()){
					puts("YES");
					return 0;
				}
			}
		}
	}
	puts("NO");
}