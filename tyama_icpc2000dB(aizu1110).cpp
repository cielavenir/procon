#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{1,0},{-1,1},{0,1},{1,1}
};
const int H=5,W=4;

map<vector<int>,int>memo;
int dfs(const vector<int> &v){
	if(v.empty())return 0;
	if(memo.find(v)!=memo.end())return memo[v];
	int r=v.size();
	for(int h=0;h<H;h++)for(int w=0;w<W&&h*W+w<v.size();w++)for(auto &d:D){
		int h1=h+d.y,w1=w+d.x;
		if(h1*W+w1<v.size() && 0<=h1&&h1<H && 0<=w1&&w1<W && v[h*W+w]==v[h1*W+w1]){
			vector<int> v1;
			for(int i=0;i<v.size();i++)if(i!=h*W+w&&i!=h1*W+w1)v1.push_back(v[i]);
			r=min(r,dfs(v1));
		}
	}
	return memo[v]=r;
}
	
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		memo.clear();
		vector<int>v(H*W);
		for(int i=0;i<H*W;i++)scanf("%d",&v[i]);
		printf("%d\n",dfs(v));
	}
}