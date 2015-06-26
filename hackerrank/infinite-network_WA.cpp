#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;
typedef struct{
	int x;
	int y;
}dir;
vector<dir>D={
	{0,1},
	{1,0},
	{0,2},
	{2,0},
	{1,1},
	{1,-1},
};

template<typename T> class union_find{
	map<T,T> parent;
public:
	T root(T a){
		if(parent.find(a)==parent.end())parent[a]=a;
		return parent[a]==a?a:(parent[a]=root(parent[a]));
	}
	int same(T a,T b){return root(a)==root(b);}
	int unite(T a,T b){
		T x=root(a),y=root(b);if(x==y)return 0;
		parent[x]=y;
		return 1;
	}
};

int main(){
	union_find<pii>uf;
	int N;
	scanf("%d",&N);
	set<pii>se;
	for(int i=0;i<N;i++){
		pii p;
		scanf("%d%d",&p.first,&p.second);
		se.insert(p);
		uf.root(p);
	}
	for(auto &e:se){
		for(auto &f:D){
			auto it=se.find({e.first+f.x,e.second+f.y});
			if(it!=se.end())uf.unite(e,*it);
		}
	}
	map<pii,pair<pii,pii> >result;
	for(auto &e:se){
		pii p=uf.root(e);
		if(result.find(p)==result.end()){
			result[p]={{e.first,e.first},{e.second,e.second}};
		}
		result[p].first.first=min(result[p].first.first,e.first);
		result[p].first.second=max(result[p].first.second,e.first);
		result[p].second.first=min(result[p].second.first,e.second);
		result[p].second.second=max(result[p].second.second,e.second);
	}
	int r=0;
	for(auto &e:result){
		r+=4+(e.second.first.second-e.second.first.first)*2+(e.second.second.second-e.second.second.first)*2;
	}
	printf("%d\n",r);
}
/*
Corner
Input
8
0 0
1 0
2 0
3 0
0 3
1 3
2 3
3 3
Output
14
*/