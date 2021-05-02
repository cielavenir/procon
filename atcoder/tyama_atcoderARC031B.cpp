#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;
typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{0,1},
	{1,0},
	{0,-1},
	{-1,0},
};

int main(){
	int n=0;
	string line;
	vector<string>v;
	for(;getline(cin,line);){
		v.push_back(line);
		for(int i=0;i<line.size();i++)n+=line[i]=='o';
	}
	for(int x=0;x<v[0].size();x++){
		for(int y=0;y<v.size();y++){
			if(v[y][x]=='x'){
				v[y][x]='o';
				queue<pii>q;
				q.push({x,y});
				map<pii,pii>back={{{x,y},{x,y}}};
				for(;!q.empty();){
					auto cur=q.front();q.pop();
					for(auto &d:D){
						if(
							0<=cur.first+d.x&&cur.first+d.x<v[0].size() &&
							0<=cur.second+d.y&&cur.second+d.y<v.size() &&
							v[cur.second+d.y][cur.first+d.x]=='o' &&
							back.find({cur.first+d.x,cur.second+d.y})==back.end()
						){
							q.push({cur.first+d.x,cur.second+d.y});
							back[{cur.first+d.x,cur.second+d.y}]=cur;
						}
					}
					
				}
				v[y][x]='x';
				if(back.size()==n+1){
					puts("YES");
					return 0;
				}
			}
		}
	}
	puts("NO");
}