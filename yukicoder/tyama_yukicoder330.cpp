#include <vector>
#include <cstdio>
using namespace std;
struct union_find{
	int *parent,n;
	int root(int a){return parent[a]<0?a:(parent[a]=root(parent[a]));}
	union_find(int _n){n=_n;parent=new int[n];for(int i=0;i<n;i++)parent[i]=-1;}
	~union_find(){delete []parent;}
	void unite(int a,int b){
		int x=root(a),y=root(b);if(x==y)return;
		parent[x]+=parent[y];
		parent[y]=x;
	}
};
int main(){
	int a,b,c,d;
	scanf("%d%d",&a,&d);
	union_find uf(a);
	for(;d--;){
		scanf("%d%d%d",&a,&b,&c);
		uf.unite(a-1,b-1);
	}
	for(c=0,d=uf.n;d--;)c+=uf.parent[d]<0;
	printf("%d\n",c);
}