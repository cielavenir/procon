#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
class union_find{
	int *parent,*s,n;
public:
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
	union_find(int _n){n=_n;parent=new int[n];s=new int[n];for(int i=0;i<n;i++)parent[i]=i,s[i]=1;}
	~union_find(){delete []parent;delete []s;}
	int same(int a,int b){return root(a)==root(b);}
	int unite(int a,int b){
		int x=root(a),y=root(b);if(x==y)return 0;
		if(s[x]>s[y] || (s[x]==s[y]&&x<y)){
			parent[y]=x;
			s[x]+=s[y];
		}else{
			parent[x]=y;
			s[y]+=s[x];
		}
		return 1;
	}
};
int main(){
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	union_find uf(n);
	for(int i=0;i<m;i++)scanf("%d%d",&a,&b),uf.unite(a-1,b-1);
	for(int i=0;i<n;i++)printf("%d\n",uf.root(i)+1);
}
