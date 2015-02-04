#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;
typedef struct{
	int x;
	int y;
}dir;
dir dirs[]={
	{1,0},
	{0,-1},
	{-1,0},
	{0,1},
};
bool dfs(pii &cur,pii &prev,set<pii>&se,const vector<string>&m){
	for(auto &d:dirs){
		pii nxt={cur.first+d.x,cur.second+d.y};
		if(
			nxt==prev ||
			nxt.first<0||m[0].size()<=nxt.first ||
			nxt.second<0||m.size()<=nxt.second ||
			m[cur.second][cur.first]!=m[nxt.second][nxt.first]
		)continue;
		if(se.find(nxt)!=se.end())return true;
		se.insert(nxt);
		if(dfs(nxt,cur,se,m))return true;
	}
	return false;
}
int main(){
	int w,h;
	cin>>h>>w;
	vector<string>m(h);
	for(int y=0;y<h;y++){
		cin>>m[y];
	}
	for(int y=0;y<h;y++)for(int x=0;x<w;x++)if(m[y][x]){
		set<pii>se;
		pii cur={x,y};
		se.insert(cur);
		if(dfs(cur,cur,se,m)){
			puts("Yes");
			return 0;
		}
		for(auto &e:se){
			m[e.second][e.first]=0;
		}
	}
	puts("No");
}