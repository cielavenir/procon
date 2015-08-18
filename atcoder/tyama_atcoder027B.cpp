#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstdio>
using namespace std;

template<typename T> class union_find{
public:
	map<T,T> parent; //never perform write access.
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
	int size(){
		set<T>s;
		for(typename map<T,T>::iterator it=parent.begin();it!=parent.end();++it)s.insert(root(*it));
		return s.size();
	}
};

int main(){
	union_find<char> uf;
	set<char>unused,unused_root,roots;
	int N;
	string s,t;
	cin>>N>>s>>t;
	char first_root=t[0];
	for(int i=0;i<N;i++){
		char cs=s[i],ct=t[i];
		if('0'<=cs&&cs<='9'){
			if('0'<=ct&&ct<='9'){
				if(i==0)first_root=0;
			}
			else unused.insert(ct),uf.unite(ct,ct);
		}else{
			if(i==0)first_root=s[0];
			if('0'<=ct&&ct<='9')unused.insert(cs),uf.unite(cs,cs);
			else uf.unite(cs,ct);
		}
	}
	for(auto &e:unused)unused_root.insert(uf.root(e));
	for(auto &e:uf.parent)if(unused_root.find(uf.root(e.first))==unused_root.end())roots.insert(uf.root(e.first));
	long long r=1;
	for(int i=0;i<roots.size();i++)r*=10;
	if(roots.find(uf.root(first_root))!=roots.end())r=r/10*9;
	printf("%lld\n",r);
}