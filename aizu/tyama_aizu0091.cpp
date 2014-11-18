#include <vector>
#include <cstdio>
#define SIZ 10
using namespace std;

const vector<pair<
	pair<int,int>,
	vector<vector<int>>
>>pattern={
	{{13,3},{
		{0,0,1,0,0},
		{0,1,1,1,0},
		{1,1,1,1,1},
		{0,1,1,1,0},
		{0,0,1,0,0},
	}},
	{{9,2},{
		{1,1,1},
		{1,1,1},
		{1,1,1},
	}},
	{{5,1},{
		{0,1,0},
		{1,1,1},
		{0,1,0},
	}},
};

int m[SIZ][SIZ];
vector<pair<pair<int,int>,int>>v;
bool dfs(int pat,int y,int x,int N,int d,int s){
	if(d==N)return s==0;
	if(s<(N-d)*5 || (N-d)*pattern[pat].first.first<s)return false;
	for(;pat<pattern.size();pat++,y=x=0)if(pattern[pat].first.first<=s){
		for(;y<=SIZ-pattern[pat].second.size();y++,x=0){
			for(;x<=SIZ-pattern[pat].second[0].size();x++){
				for(int dy=0;dy<pattern[pat].second.size();dy++){
					for(int dx=0;dx<pattern[pat].second[0].size();dx++){
						if(m[y+dy][x+dx]<pattern[pat].second[dy][dx])goto fail;
					}
				}
				for(int dy=0;dy<pattern[pat].second.size();dy++){
					for(int dx=0;dx<pattern[pat].second[0].size();dx++){
						m[y+dy][x+dx]-=pattern[pat].second[dy][dx];
					}
				}
				v[d]=make_pair(
					make_pair(x+pattern[pat].second[0].size()/2,y+pattern[pat].second.size()/2),
					pattern[pat].first.second
				);
				if(dfs(pat,y,x,N,d+1,s-pattern[pat].first.first))return true;
				for(int dy=0;dy<pattern[pat].second.size();dy++){
					for(int dx=0;dx<pattern[pat].second[0].size();dx++){
						m[y+dy][x+dx]+=pattern[pat].second[dy][dx];
					}
				}
				fail:;
			}
		}
	}
	return false;
}

int main(){
	int N,y,x,s=0;
	scanf("%d",&N);
	for(y=0;y<SIZ;y++)for(x=0;x<SIZ;x++)scanf("%d",m[y]+x),s+=m[y][x];
	v.resize(N);
	dfs(0,0,0,N,0,s);
	for(x=0;x<N;x++)printf("%d %d %d\n",v[x].first.first,v[x].first.second,v[x].second);
}