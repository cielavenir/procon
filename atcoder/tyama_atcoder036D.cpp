#include <vector>
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
};
int main(){
	int N,Q;
	scanf("%d%d",&N,&Q);
	union_find uf(N*2);
	for(;Q--;){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);b--;c--;
		if(a==1){
			if(d%2){
				uf.unite(N+b,c);
				uf.unite(b,N+c);
			}else{
				uf.unite(b,c);
				uf.unite(N+b,N+c);
			}
		}else{
			puts(uf.same(b,c)?"YES":"NO");
		}
	}
}