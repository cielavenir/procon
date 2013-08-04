#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#define SENTINEL 99999999
using namespace std;
typedef pair<int,int> pii;
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
		parent[x.first]=make_pair(y.first,y.second-x.second+w);
		return 1;
	}
};
int main(){
	char s[2];
	int N,Q,a,b,w;
	for(;scanf("%d%d",&N,&Q),N;)for(union_find uf(N);Q--;){
		scanf("%s",s);if(*s=='!'){
			scanf("%d%d%d",&a,&b,&w),a--,b--;
			uf.unite(a,b,w);
		}else{
			scanf("%d%d",&a,&b),a--,b--;
			w=uf.dist(a,b);
			printf(w==SENTINEL?"UNKNOWN\n":"%d\n",w);
		}
	}
}