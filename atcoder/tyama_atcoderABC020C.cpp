#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{0,-1},{0,1},{-1,0},{1,0}
};

long long bfs(const vector<string>&v,const pii &start,const pii &goal,long long cost){
	queue<pii>q;
	map<pii,long long>depth;
	depth[start]=0;
	for(q.push(start);!q.empty();){
		pii cur=q.front();q.pop();
		for(auto d:D){
			pii nxt={cur.first+d.x,cur.second+d.y};
			if(
				0<=nxt.first&&nxt.first<v[0].size() &&
				0<=nxt.second&&nxt.second<v.size() &&
				(depth.find(nxt)==depth.end() || depth[nxt]>depth[cur]+(v[nxt.second][nxt.first]=='#'?cost:1))
			){
				q.push(nxt);
				depth[nxt]=depth[cur]+(v[nxt.second][nxt.first]=='#'?cost:1);
			}
		}
	}
	return depth[{goal.first,goal.second}];
}

int main(){
	int H,W;
	long long T;
	cin>>H>>W>>T;
	vector<string>v(H);
	pii start,goal;
	for(int i=0;i<H;i++){
		cin>>v[i];
		for(int j=0;j<W;j++){
			if(v[i][j]=='S')start={j,i};
			if(v[i][j]=='G')goal={j,i};
		}
	}
	long long lo=1,hi=T;
	for(;lo+1<hi;){
		long long me=(lo+hi)/2;
		if(bfs(v,start,goal,me)<=T){
			lo=me;
		}else{
			hi=me;
		}
	}
	cout<<lo<<endl;
}