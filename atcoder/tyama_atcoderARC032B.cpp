#include <map>
#include <cstdio>
using namespace std;
class union_find{
	int *parent,n;
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
public:
	union_find(int _n){n=_n;parent=new int[n+1];for(int i=1;i<=n;i++)parent[i]=i;}
	~union_find(){delete []parent;}
	int unite(int a,int b){
		int x=root(a),y=root(b);
		if(x==y)return 0;
		parent[x]=y;
		return 1;
	}
	int size(){
		map<int,int> m;
		for(int i=1;i<=n;i++)m[root(i)]++;
		return m.size();
	}
};
int main(){
	int N,M,a,b;
	scanf("%d%d",&N,&M);
	union_find uf(N);
	for(;M--;uf.unite(a,b))scanf("%d%d",&a,&b);
	printf("%d\n",uf.size()-1);
}