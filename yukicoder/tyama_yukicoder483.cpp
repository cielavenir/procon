#include <vector>
#include <map>
#include <set>
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
		T x=root(a),y=root(b);//if(x==y)return 0;
		parent[x]=y;
		return 1;
	}
	map<T,int> size(){
		map<T,int> r;
		for(auto &e:parent)r[root(e.first)]++;
		return r;
	}
};
int main(){
	union_find<pair<int,int>>uf;
	map<pair<int,int>,int>v;
	int n,a,b,c,d;
	for(scanf("%d",&n);n--;){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		uf.unite({a,b},{c,d});
		v[{a,b}]++;
	}
	for(auto &e:v){
		auto r=uf.root(e.first);
		if(r!=e.first)v[r]+=e.second;
	}
	for(auto &e:uf.size()){
		if(e.second+1<=v[e.first]){puts("NO");return 0;}
	}
	puts("YES");
}
