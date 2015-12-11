#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdio>
using namespace std;
class union_find{
	int *parent,*rank,n;
public:
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
	union_find(int _n){n=_n;parent=new int[n];rank=new int[n];for(int i=0;i<n;i++)parent[i]=i,rank[i]=0;}
	~union_find(){delete []parent;delete []rank;}
	void unite(int a,int b){
		int x=root(a),y=root(b);
		if(rank[x]<rank[y]){
			parent[x]=y;
		}else{
			parent[y]=x;
			if(rank[x]==rank[y])rank[x]++;
		}
	}
	void enumerate(unordered_map<int,int> &sizes){
		unordered_map<int,int> r;
		for(int i=0;i<n;i++)++r[root(i)];
		for(auto &e:r)sizes[e.second]++;
	}
};
int main(){
	const int INF=1<<29;
	int N,M;
	scanf("%d%d",&N,&M);
	union_find uf(N);
	for(;M--;){
		int a,b;
		scanf("%d%d",&a,&b);
		uf.unite(a-1,b-1);
	}
	unordered_map<int,int>sizes;
	uf.enumerate(sizes);
	vector<int>bag(N+1,N);
	bag[0]=-1;
	int t=0;
	for(auto &e:sizes){
		int n=e.second;
#if 1
		for(int d=1;n;d*=2){
			int x=min(d,n);
			n-=x;
			int y=e.first*x;
			t+=y;
			for(int i=t;i>=y;i--)if(bag[i-y]<N){
				bag[i]=min(bag[i],bag[i-y]+x);
			}
		}
#else
		for(int j=n;j--;){
			t+=e.first;
			for(int i=t;i>=e.first;i--)if(bag[i-e.first]<N){
				bag[i]=min(bag[i],bag[i-e.first]+1);
			}
		}
#endif
	}
	for(int i=1;i<=N;i++)printf("%d\n",bag[i]==N ? -1 : bag[i]);
}