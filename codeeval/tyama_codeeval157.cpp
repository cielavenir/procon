#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> pii;

const int D[4][2]={
	{-1,0},
	{0,-1},
	{1,0},
	{0,1},
};

int main(){
	vector<string>v;
	string line;
	int i;
	for(;getline(cin,line);)v.push_back(line);
	for(i=0;i<v[0].size();i++)if(v[0][i]==' ')break;
	pii start=make_pair(i,0);
	map<pii,pii>back;
	back[start]=start;
	back[make_pair(i,1)]=start;
	queue<pii>q;
	q.push(make_pair(i,1));
	for(i=0;i<v[0].size();i++)if(v[v.size()-1][i]==' ')break;
	pii goal=make_pair(i,v.size()-1);
	for(;!q.empty();){
		pii cur=q.front();q.pop();
		for(i=0;i<4;i++){
			int x=cur.first+D[i][0],y=cur.second+D[i][1];
			pii nxt=make_pair(x,y);
			if(v[y][x]==' '&&back.find(nxt)==back.end()){
				back[nxt]=cur;
				q.push(nxt);
				if(nxt==goal){
					for(;back[nxt]!=nxt;nxt=back[nxt]){
						int x=nxt.first,y=nxt.second;
						v[y][x]='+';
					}
					int x=nxt.first,y=nxt.second;
					v[y][x]='+';
					for(i=0;i<v.size();i++)cout<<v[i]<<endl;
					return 0;
				}
			}
		}
	}
	return 1;
}