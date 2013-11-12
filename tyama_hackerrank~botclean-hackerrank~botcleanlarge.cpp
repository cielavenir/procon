#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <cstdlib>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> ppiii;
int D[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
string dir[]={"UP","DOWN","LEFT","RIGHT"};

map<pii,pair<pii,string> >back;
void backtrack(pii cur){
	if(back[cur].first!=cur){
		backtrack(back[cur].first);
		puts(back[cur].second.c_str());
		exit(0);
	}
}

char s;
int main(){
	int n,m,x,y,i,j;
	cin>>y>>x;
	pii start=make_pair(y,x);
#if 0
	n=5,m=5;
#else
	cin>>m>>n;
#endif
	vector<string>v;
	string s;
	for(i=0;i<=m;i++)cin>>s,v.push_back(s);
	if(v[y][x]=='d')puts("CLEAN"),exit(0);

	queue<ppiii> q;
	map<pii,int>visit;
	q.push(make_pair(start,0));
	visit[start]=0;
	back[start]=make_pair(start,"");
	for(;!q.empty();){
		ppiii cur=q.front();q.pop();
		for(i=0;i<4;i++){
			int nexty=cur.first.first+D[i][0];
			int nextx=cur.first.second+D[i][1];
			pii next=make_pair(nexty,nextx);
			if(
				0<=nexty&&nexty<m &&
				0<=nextx&&nextx<n &&
				visit.find(next)==visit.end()
			){
				q.push(make_pair(next,cur.second+1));
				visit[next]=cur.second+1;
				back[next]=make_pair(cur.first,dir[i]);
				if(v[next.first][next.second]=='d'){
					backtrack(next);
					//printf("%d\n",cur.second+1);
					return 0;
				}
			}
		}
	}
	//queue exhausted
	puts("Fail");
}