#include <vector>
#include <set>
#include <cstdio>
using namespace std;
class union_find{
	int *parent,n;
public:
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
	union_find(int _n){n=_n;parent=new int[n];for(int i=1;i<n;i++)parent[i]=i;}
	~union_find(){delete []parent;}
	int same(int a,int b){return root(a)==root(b);}
	int unite(int a,int b){
		int x=root(a),y=root(b);//if(x==y)return 0;
		parent[x]=y;
		return 1;
	}
};
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	union_find uf(N);
	vector<int> f(N);
	set<int> se;
	for(;M--;){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		if(uf.same(a,b))f[a]=1;
		else uf.unite(a,b);
	}
	for(int i=0;i<N;i++)f[uf.root(i)]|=f[i];
	for(int i=0;i<N;i++)if(!f[uf.root(i)])se.insert(uf.root(i));
	printf("%d\n",se.size());
}