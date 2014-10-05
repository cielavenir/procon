#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
class union_find{
	int *parent,n;
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
public:
	union_find(int _n){n=_n;parent=new int[n+1];for(int i=1;i<=n;i++)parent[i]=i;}
	~union_find(){delete []parent;}
	int same(int a,int b){return root(a)==root(b);}
	int unite(int a,int b){
		int x=root(a),y=root(b);//if(x==y)return 0;
		parent[x]=y;
		return 1;
	}
	int size(){
		set<int>s;
		for(int i=1;i<=n;i++)s.insert(root(i));
		return s.size();
	}
};
int main(){
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	union_find un(n);
	for(;m--;){
		scanf("%d%d",&a,&b);
		un.unite(a,b);
	}
	printf("%d\n",un.size()-1);
}