//ported from ICPC2012rF
#include <iostream>
#include <string>
#include <vector>
#include <map>
#define SENTINEL 99999999
using namespace std;
typedef pair<int,int> pii;
map<int,int>h;
class union_find{
	vector<pii>parent;
	pii root(int a){
		if(parent[a].first==a)return parent[a];
		pii ret=root(parent[a].first);
		return parent[a]=make_pair(ret.first,ret.second+parent[a].second);
	}
public:
	union_find(int n): parent(n){for(int i=0;i<n;i++)parent[i]=make_pair(i,0);}
	int dist(int a,int b){
		pii x=root(a),y=root(b);
		if(x.first!=y.first)return SENTINEL;
		return x.second-y.second;
	}
	int unite(int a,int b,int w){
		pii x=root(a),y=root(b);
		if(x.first==y.first)return 0;
		parent[x.first]=make_pair(y.first,y.second-x.second -w-h[a]+h[b]); ///
		return 1;
	}
};
int main(){
	int N,Q,a,b,w;
	string s;
	cin>>N>>Q;
	union_find uf(N);
	for(;Q--;){
		cin>>s>>a>>b,a--,b--;
		if(s=="IN"){
			cin>>w;
			h[a]+=w,h[b]+=w;
			uf.unite(a,b,w);
		}else{
			w=uf.dist(a,b);
			if(w==SENTINEL)cout<<"WARNING"<<endl;
			else cout<< -w-h[a]+h[b]<<endl; ///
		}
	}
}