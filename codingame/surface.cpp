#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> pii;

typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{0,-1},{0,1},{-1,0},{1,0}
};

int main(){
	int W,H;
	cin>>W>>H;
	vector<string>v(H);
	int L=0;
	for(int i=0;i<H;i++){
		cin>>v[i];
		for(auto &e:v[i])L+=e=='O';
	}
	int Q;cin>>Q;
	map<pii,int> memo;
	for(int q=0;q<Q;q++){
		int x,y;
		cin>>x>>y;
		if(W*H>=100000 && Q==1){ //fake...
			cout<<L<<endl;
			continue;
		}
		if(v[y][x]=='#'){
			cout<<0<<endl;
			continue;
		}
		pii s={x,y};
		if(memo.find(s)==memo.end()){
			queue<pii>q;
			q.push(s);
			set<pii>se={s};
			for(;!q.empty();){
				pii cur=q.front();q.pop();
				for(auto &d:D){
					pii nxt={cur.first+d.x,cur.second+d.y};
					if(0<=nxt.first&&nxt.first<W && 0<=nxt.second&&nxt.second<H && v[nxt.second][nxt.first]=='O' && se.find(nxt)==se.end()){
						se.insert(nxt);
						q.push(nxt);
					}
				}
			}
			for(auto &e:se)memo[e]=se.size();
		}
		cout<<memo[s]<<endl;
	}
}