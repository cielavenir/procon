#include <map>
#include <string>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> ppiii;
int M[1001][1001];
int D[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
string dir[]={"UP","LEFT","DOWN","RIGHT"};

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
	int n=5,m=5,i,j;
	pii start=make_pair(-1,-1),goal;
	scanf("%d%d",&i,&i);m=n;getchar();
	for(i=0;i<m;getchar(),i++)for(j=0;j<n;j++){
		s=getchar();
		switch(s){
			case 'b':start=make_pair(i,j);M[i][j]=0;break;
			case 'd':goal=make_pair(i,j);M[i][j]=0;break;
			case '-':M[i][j]=0;break;
			case '%':M[i][j]=1;break;
		}
	}
	if(start==make_pair(-1,-1))puts("CLEAN"),exit(0);
	
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
				!M[nexty][nextx] &&
				visit.find(next)==visit.end()
			){
				q.push(make_pair(next,cur.second+1));
				visit[next]=cur.second+1;
				back[next]=make_pair(cur.first,dir[i]);
				if(next==goal){
					backtrack(goal);
					//printf("%d\n",cur.second+1);
					return 0;
				}
			}
		}
	}
	//queue exhausted
	puts("Fail");
}