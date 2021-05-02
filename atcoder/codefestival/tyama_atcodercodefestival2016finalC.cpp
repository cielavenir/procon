#include <vector>
#include <cstdio>
using namespace std;
class union_find{
	int *parent,n;
public:
	union_find(int _n){n=_n;parent=new int[n+1];for(int i=1;i<=n;i++)parent[i]=i;}
	~union_find(){delete []parent;}
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
	int unite(int a,int b){
		int x=root(a),y=root(b);
		if(x==y)return 0;
		parent[x]=y;
		return 1;
	}
};
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	union_find uf(M);
	vector<int>v(M+1);
	for(;N--;){
		int n,x,y;
		scanf("%d%d",&n,&x);
		v[x]++;
		n--;
		for(;n--;){
			scanf("%d",&y);
			uf.unite(x,y);
			v[y]++;
		}
	}
	int root=-1;
	for(int i=1;i<=M;i++){
		if(v[i]){
			if(root<0)root=uf.root(i);
			else if(root!=uf.root(i)){puts("NO");return 0;}
		}
	}
	puts("YES");
}
