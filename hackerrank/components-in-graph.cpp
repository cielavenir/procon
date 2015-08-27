#include <map>
#include <set>
#include <cstdio>
using namespace std;

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
	union_find<int>uf;
	int N;
	scanf("%d",&N);
	set<int>se;
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		se.insert(x);
		se.insert(y);
		uf.unite(x,y);
	}
	map<int,set<int> >m;
	for(auto &e:se)m[uf.root(e)].insert(e);
	int ma=0,mi=2*N;
	for(auto &e:m){
		if(ma<e.second.size())ma=e.second.size();
		if(mi>e.second.size())mi=e.second.size();
	}
	printf("%d %d\n",mi,ma);
}