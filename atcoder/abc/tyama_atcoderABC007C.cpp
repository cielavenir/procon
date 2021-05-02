#include <map>
#include <queue>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> ppiii;
int M[1001][1001];
int D[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

map<pii,pii>back;
void backtrack(int d,pii cur){
	if(back[cur]==cur){
		printf("%d\n",d);
	}else{
		backtrack(d+1,back[cur]);
	}
	//printf("%d %d\n",cur.first,cur.second);
}

char s;
int main(){
	int n,m,i,j,x,y;
	pii start,goal;
	scanf("%d%d%d%d%d%d",&m,&n,&i,&j,&x,&y);getchar();
	start=make_pair(i-1,j-1);
	goal=make_pair(x-1,y-1);
	for(i=0;i<m;getchar(),i++)for(j=0;j<n;j++){
		s=getchar();
		switch(s){
			case '.':M[i][j]=0;break;
			case '#':M[i][j]=1;break;
		}
	}
	vector<pii> v;
	queue<ppiii> q;
	map<pii,int>visit;
	v.push_back(start);
	q.push(make_pair(start,0));
	visit[start]=0;
	back[start]=start;
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
				v.push_back(next);
				q.push(make_pair(next,cur.second+1));
				visit[next]=cur.second+1;
				back[next]=cur.first;
				if(next==goal){
					backtrack(0,goal);
					return 0;
				}
			}
		}
	}
	//queue exhausted
	puts("Fail");
}