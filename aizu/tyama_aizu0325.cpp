#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cstdio>
using namespace std;

template<typename T> class union_find{
	unordered_map<T,T> parent;
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
	int size(){
		unordered_set<T>se;
		for(auto &e:parent)se.insert(root(e.first));
		return se.size();
	}
};

int main(){
	int n,i;
	vector<pair<int,int> >v(6);
	union_find<int>uf;
	unordered_map<int,int>cnt;
	int f=0;
	for(i=0;i<6;i++){
		scanf("%d%d",&v[i].first,&v[i].second);
		if(v[i].first>v[i].second)swap(v[i].first,v[i].second);
		uf.unite(v[i].first,v[i].second);
		cnt[v[i].first]++;
		cnt[v[i].second]++;
	}
	sort(v.begin(),v.end());
	puts(all_of(cnt.begin(),cnt.end(),[](auto &a){return a.second%4==0;}) && uf.size()==1 && v[0]==v[1] && v[2]==v[3] && v[4]==v[5] ? "yes" : "no");
}
