#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

template<typename T> class union_find{
	unordered_map<T,T> parent;
	unordered_map<string,int> tbl;
public:
	T root(T a){
		if(parent.find(a)==parent.end())parent[a]=a;
		return parent[a]==a?a:(parent[a]=root(parent[a]));
	}
	int same(T a,T b){return root(a)==root(b);}
	int unite(T a,T b,int p,int q){
		T x=root(a),y=root(b);if(x==y)return 0;
		parent[x]=y;
		tbl[y]=min(min(tbl[x]?:1<<29,tbl[y]?:1<<29),min(p,q));
		tbl.erase(x);
		return 1;
	}
	int get(T a){
		return tbl[root(a)];
	}
};

int main(){
	int N;
	unordered_map<string,int>m;
	for(cin>>N;N--;){
		string s;int x;
		cin>>s>>x;
		m[s]=x;
	}
	union_find<string> uf;
	for(cin>>N;N--;){
		string s,t;
		cin>>s>>t;
		uf.unite(s,t,m[s],m[t]);
	}
	int r=0;
	for(auto &e:m){
		r+=uf.get(e.first)?:e.second;
	}
	cout<<r<<endl;
}