#include <vector>
#include <cstdio>
using namespace std;
class union_find{
	int *parent,*rank,n;
public:
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
	union_find(int _n){n=_n;parent=new int[n];rank=new int[n];for(int i=0;i<n;i++)parent[i]=i,rank[i]=0;}
	~union_find(){delete []parent;delete []rank;}
	int unite(int a,int b){
		int x=root(a),y=root(b);if(x==y)return 0;
		if(rank[x]<rank[y]){
			parent[x]=y;
		}else{
			parent[y]=x;
			if(rank[x]==rank[y])rank[x]++;
		}
		return 1;
	}
};
int main(){
	int N,K;
	scanf("%d%d%d",&N,&K,&K);
	union_find uf(N+1);
	vector<int>v(N+1);
	for(int i=1;i<=K;i++){
		int c,a,b;
		scanf("%d%d%d",&c,&a,&b);
		if(c==1){
			if(v[uf.root(a)]&&v[uf.root(b)]&&v[uf.root(a)]!=v[uf.root(b)]){
				printf("%d\n",i);return 0;
			}
			if(!v[uf.root(a)])v[uf.root(a)]=v[uf.root(b)];
			if(!v[uf.root(b)])v[uf.root(b)]=v[uf.root(a)];
			uf.unite(a,b);
		}else{
			if(v[uf.root(a)]&&v[uf.root(a)]!=b){
				printf("%d\n",i);return 0;
			}
			v[uf.root(a)]=b;
		}
	}
	puts("0");
}
