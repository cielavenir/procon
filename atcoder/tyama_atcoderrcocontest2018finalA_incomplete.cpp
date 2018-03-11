#pragma GCC optimize("O3")
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <algorithm>
#include <ctime>
#include <unistd.h>
using namespace std;
typedef pair<int,int> pii;

const int D[4][2]={ //Right,Up,Left,Down
	{0,1},
	{-1,0},
	{0,-1},
	{1,0},
};

int main(){
	mt19937_64 engine((unsigned int)time(NULL)^(getpid()<<16));
	int N,K;
	scanf("%d%d",&N,&K);
	vector<vector<int>>m(N);for(auto &e:m)e.resize(N);
	vector<pair<pii,pii>>v(K);
	set<pii>forbidden_list;
	for(auto &e:v){
		scanf("%d%d%d%d",&e.first.first,&e.first.second,&e.second.first,&e.second.second);
		forbidden_list.insert(e.first);
		forbidden_list.insert(e.second);
	}
	for(auto &e:v){
		pii R={-1,-1};
		pii &es=e.first,&ed=e.second;
		vector<pii>candidates;
		if(1){//es.first!=ed.first && es.second!=ed.second){
			for(int r=min(es.first,ed.first);r<=max(es.first,ed.first);r++){
				for(int c=min(es.second,ed.second);c<=max(es.second,ed.second);c++){
					pii k={r,c};
					if(!m[r][c]&&forbidden_list.find(k)==forbidden_list.end()){
						candidates.push_back(k);
					}
				}
			}
			shuffle(candidates.begin(),candidates.end(),engine);
			int K=50,c=0;
			for(auto &e:candidates){
				m[e.first][e.second]=1;
				int c0=-1;
				map<pii,int>depth={{es,0}};
				queue<pii>q;q.push(es);
				for(;!q.empty();){
					pii cur=q.front();q.pop();
					int y=cur.first,x=cur.second;
					int d=0;
					for(;d<4;d++){
						int ny=cur.first+D[d][1],nx=cur.second+D[d][0];
						pii nxt={ny,nx};
						if(0<=nx&&nx<N && 0<=ny&&ny<N && !m[ny][nx] && depth.find(nxt)==depth.end()){
							q.push(nxt);
							depth[nxt]=depth[cur]+1;
							if(nxt==ed){
								c0=depth[nxt];
								d=5;break;
							}
						}
					}
					if(d==5)break;
				}
				m[e.first][e.second]=0;
				if(c0>c){
					c=c0;
					R=e;
				}
				if(--K)break;
			}
		}
		if(R.first>=0)m[R.first][R.second]=1;
		printf("%d %d\n",R.first,R.second);
	}
}
