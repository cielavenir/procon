#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> ppiii;
int M[1001][1001];
int D[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int main(){
    int n,m,i,j;
	string s;
	pii start,goal;
	cin>>m>>n;
	for(i=0;i<m;i++)for(cin>>s,j=0;j<n;j++){
		switch(s[j]){
			case 's':start=make_pair(i,j);M[i][j]=0;break;
			case 'g':goal=make_pair(i,j);M[i][j]=0;break;
			case '.':M[i][j]=0;break;
			case '#':M[i][j]=1;break;
		}
	}
	queue<ppiii> q;
	map<pii,int>visit;
	q.push(make_pair(start,0));
	visit[start]=0;
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
				if(next==goal){
					cout<<"Yes"<<endl;//cur.second+1<<endl;
					return 0;
				}
			}
		}
	}
	//queue exhausted
	cout<<"No"<<endl;
}