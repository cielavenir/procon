#include <cstdio>
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
};
main(){
	int N,M,Q,c,d;
	scanf("%d%d%d",&N,&M,&Q);
	union_find uf(N+M);
	for(;Q--;){
		scanf("%d%d",&c,&d);
		uf.unite(c-1,N+d-1);
	}
	for(c=d=0;d<N+M;d++)if(uf.unite(d%N,N+d%M))c=d+1;
	printf("%d\n",c);
}