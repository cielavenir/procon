#include <vector>
#include <set>
#include <cstdio>
using namespace std;
class union_find{
	int *parent,n;
public:
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
	union_find(int _n){n=_n;parent=new int[n];for(int i=0;i<n;i++)parent[i]=i;}
	~union_find(){delete []parent;}
	int same(int a,int b){return root(a)==root(b);}
	int unite(int a,int b){
		int x=root(a),y=root(b);if(x==y)return 0;
		parent[x]=y;
		return 1;
	}
	int size(){
		set<int>s;
		for(int i=0;i<n;i++)s.insert(root(i));
		return s.size();
	}
};
int main(){
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	union_find uf(n);
	for(;m--;){
		scanf("%d%d",&x,&y);
		uf.unite(x-1,y-1);
	}
	puts(uf.size()==1?"YES":"NO");
	return 0;
}