#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
class union_find{
	std::vector<int> parent;
public:
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
	union_find(int n):parent(n+1){for(int i=1;i<=n;i++)parent[i]=i;}
	int same(int a,int b){return root(a)==root(b);}
	int unite(int a,int b){
		int x=root(a),y=root(b);//if(x==y)return 0;
		parent[x]=y;
		return 1;
	}
	int calc(){
		std::map<int,int> m;
		for(int i=1;i<parent.size();i++)m[root(i)]++;
		int r=0;
		for(auto &e:m)r+=e.second>1?1:-1;
		return abs(r);
	}
};
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	union_find uf(n);
	int a,b;
	for(;m--;uf.unite(a,b))scanf("%d%d",&a,&b);
	printf("%d\n",uf.calc());
}