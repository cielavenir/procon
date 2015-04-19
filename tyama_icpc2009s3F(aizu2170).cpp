#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

class union_find{
	vector<int> parent;
public:
	vector<int> marked;
	int root(int a){return parent[a]==a||marked[a]?a:(parent[a]=root(parent[a]));}
	union_find(int n):parent(n),marked(n){for(int i=1;i<n;i++)parent[i]=i;}
	int same(int a,int b){return root(a)==root(b);}
	int unite(int a,int b){
		int x=root(a),y=root(b);//if(x==y)return 0;
		parent[x]=y;
		return 1;
	}
};

int main(){
	int N,M;
	for(;~scanf("%d%d",&N,&M)&&N;){
		vector<int>parent(N);
		for(int i=1;i<N;i++)scanf("%d",&parent[i]),parent[i]--;
		union_find uf(N);
		vector<pair<char,int> >query;
		for(int i=0;i<M;i++){
			char s[2];int n;
			scanf("%s%d",s,&n),n--;
			if(*s=='Q'||!uf.marked[n]){
				if(*s=='M')uf.marked[n]=1;
				query.emplace_back(*s,n);
			}
		}
		for(int i=1;i<N;i++)if(!uf.marked[i])uf.unite(i,parent[i]);
		reverse(query.begin(),query.end());
		long long R=0;
		for(auto &e:query){
			if(e.first=='Q')R+=uf.root(e.second)+1;
			else uf.marked[e.second]=0,uf.unite(e.second,parent[e.second]);
		}
		printf("%lld\n",R);
	}
}