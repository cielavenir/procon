#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#if 0
typedef pair<int,int> pii;
#define fst(a) (a.first)
#define snd(b) (b.second)
#define mp(a,b) (make_pair(a,b))
#else
typedef long long pii;
#define fst(a) (a>>32)
#define snd(b) (b&0xffffffff)
#define mp(a,b) (((long long)(a))<<32 | (b))
#endif

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
	unordered_map<pii,int> memo;
	for(int q=0;q<Q;q++){
		int x,y;
		cin>>x>>y;
		/*
		//fake
		//can be avoided by using hash-table
		if(W*H>=100000 && Q==1){
			cout<<L<<endl;
			continue;
		}
		*/
		if(v[y][x]=='#'){
			cout<<0<<endl;
			continue;
		}
		pii s=mp(x,y);
		if(memo.find(s)==memo.end()){
			queue<pii>q;
			q.push(s);
			unordered_set<pii>se={s};
			for(;!q.empty();){
				pii cur=q.front();q.pop();
				for(auto &d:D){
					pii nxt=mp(fst(cur)+d.x,snd(cur)+d.y);
					if(0<=fst(nxt)&&fst(nxt)<W && 0<=snd(nxt)&&snd(nxt)<H && v[snd(nxt)][fst(nxt)]=='O' && se.find(nxt)==se.end()){
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