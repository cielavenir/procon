#include <vector>
#include <set>
#include <cstdio>
using namespace std;
class union_find{
	int *parent,*rank,n;
public:
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
	union_find(int _n){n=_n;parent=new int[n];rank=new int[n];for(int i=0;i<n;i++)parent[i]=i,rank[i]=0;}
	~union_find(){delete []parent;delete []rank;}
	int same(int a,int b){return root(a)==root(b);}
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
	int N,K,R=0;
	scanf("%d%d",&N,&K);
	union_find uf(3*N);
	for(;K--;){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y),x--,y--;
		if(x<0||N<=x || y<0||N<=y){R++;continue;}
		if(t==1){
			if(uf.same(x,y+N) || uf.same(x,y+N*2))R++;
			else{
				uf.unite(x,y);
				uf.unite(x+N,y+N);
				uf.unite(x+N*2,y+N*2);
			}
		}else{
			if(uf.same(x,y) || uf.same(x,y+N*2))R++;
			else{
				uf.unite(x,y+N);
				uf.unite(x+N,y+N*2);
				uf.unite(x+N*2,y);
			}
		}
	}
	printf("%d\n",R);
}