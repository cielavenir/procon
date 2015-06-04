#include <vector>
#include <set>
#include <cstdio>
using namespace std;
class union_find{
	int *parent,*rank,*num,n;
public:
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
	int size(int n){return num[root(n)];}
	union_find(int _n){n=_n;parent=new int[n];rank=new int[n];num=new int[n];for(int i=0;i<n;i++)parent[i]=i,rank[i]=0,num[i]=1;}
	~union_find(){delete []parent;delete []rank;delete []num;}
	int same(int a,int b){return root(a)==root(b);}
	int unite(int a,int b){
		int x=root(a),y=root(b);if(x==y)return 0;
		if(rank[x]<rank[y]){
			parent[x]=y;
			num[y]+=num[x];
		}else{
			parent[y]=x;
			num[x]+=num[y];
			if(rank[x]==rank[y])rank[x]++;
		}
		return 1;
	}
};
int main(){
	int N,K,R=0;
	scanf("%d%d",&N,&K);
	union_find uf(N);
	for(;K--;){
		char s[2];
		int x,y;
		scanf("%s",s);
		if(*s=='Q'){
			scanf("%d",&x);
			printf("%d\n",uf.size(x-1));
		}else{
			scanf("%d%d",&x,&y);
			uf.unite(x-1,y-1);
		}
	}
}