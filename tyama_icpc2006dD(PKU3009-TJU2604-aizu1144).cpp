#include <vector>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;

typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{0,-1},{0,1},{-1,0},{1,0}
};
const int max_depth=10;

int dfs2(int x,int y,const dir &d,vector<vector<int> >&m){
	if(x<0||m[0].size()<=x || y<0||m.size()<=y)return -1;
	if(m[y][x]==1||m[y][x]==3)return 0;
	int r=dfs2(x+d.x,y+d.y,d,m);
	if(r<0)return -1;
	return r+1;
}
int dfs(int depth,int x,int y,vector<vector<int> >&m,pii &goal){
	if(depth>max_depth-1)return -1;
	int ret=-1;
	for(auto &d:D){
		int dist=dfs2(x+d.x,y+d.y,d,m);
		if(dist>=0){
			pii p={x+d.x*(dist+1),y+d.y*(dist+1)};
			if(p==goal)return depth+1;
			if(dist>0){
				m[p.second][p.first]=0;
				int r=dfs(depth+1,p.first-d.x,p.second-d.y,m,goal);
				m[p.second][p.first]=1;
				if(r>=0 && (ret<0||ret>r))ret=r;
			}
		}
	}
	return ret;
}

int main(){
	int W,H;
	for(;scanf("%d%d",&W,&H),H;){
		pii start,goal;
		vector<vector<int> >v(H);
		for(int y=0;y<H;y++){
			v[y].resize(W);
			for(int x=0;x<W;x++){
				scanf("%d",&v[y][x]);
				if(v[y][x]==2)start={x,y};
				if(v[y][x]==3)goal={x,y};
			}
		}
		printf("%d\n",dfs(0,start.first,start.second,v,goal));
	}
}