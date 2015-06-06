#include <vector>
#include <map>
#include <iostream>
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
};
int main(){
	union_find<int>uf;
	int n,m;
	cin>>n>>m;
	int a,b,c;
	for(;m--;){
		cin>>a>>b>>c;
		if(!a)uf.unite(b,c);
		else cout<<(uf.same(b,c)?"Yes":"No")<<endl;
	}
}