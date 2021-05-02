#include <map>
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

void perform(int X,union_find &uf){
	for(int i=0;i<X;i++){
		int a,b;
		scanf("%d%d",&a,&b);a--,b--;
		if(a>b)swap(a,b);
		uf.unite(a,b);
	}
}

int main(){
	int N,K,L;
	scanf("%d%d%d",&N,&K,&L);
	union_find ufk(N),ufl(N);
	perform(K,ufk);
	perform(L,ufl);
	vector<pair<int,int> >m(N);
	map<pair<int,int>,int>q;
	for(int i=0;i<N;i++){
		pair<int,int>p=make_pair(ufk.root(i),ufl.root(i));
		m[i]=p;
		q[p]++;
	}
	for(int i=0;i<N;i++)printf(i<N-1 ? "%d " : "%d\n",q[m[i]]);
}
