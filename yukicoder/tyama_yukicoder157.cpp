#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <cstdlib>
using namespace std;
typedef pair<int,int> pii;
typedef struct{
	int x;
	int y;
}dir;
dir D[]={
	{0,-1},{0,1},
	{-1,0},{1,0},
};
int manhattan(const pii &a,const pii &b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}
int main(){
	int W,H;
	cin>>W>>H;
	vector<string>v(H);
	for(int i=0;i<H;i++)cin>>v[i];
	vector<set<pii> >lst;
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(v[i][j]=='.'){
		v[i][j]='#';
		set<pii> se={{i,j}};
		queue<pii> q;
		for(q.push({i,j});!q.empty();){
			pii cur=q.front();q.pop();
			for(auto &d:D){
				pii nxt={cur.first+d.y,cur.second+d.x};
				if(0<=nxt.first&&nxt.first<H && 0<=nxt.second&&nxt.second<W && v[nxt.first][nxt.second]=='.'){
					v[nxt.first][nxt.second]='#';
					se.insert(nxt);
					q.push(nxt);
				}
			}
		}
		lst.emplace_back(se);
	}
	int r=1<<29;
	for(const pii &e:lst[0])for(const pii &f:lst[1]){
		r=min(r,manhattan(e,f));
	}
	cout<<r-1<<endl;
}