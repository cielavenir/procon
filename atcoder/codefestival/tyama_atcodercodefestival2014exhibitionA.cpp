#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
using namespace std;

class union_find{
	int *parent,n;
public:
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
	union_find(int _n){n=_n;parent=new int[n];for(int i=0;i<n;i++)parent[i]=i;}
	~union_find(){delete []parent;}
	int same(int a,int b){return root(a)==root(b);}
	int unite(int a,int b){
		int x=root(a),y=root(b);//if(x==y)return 0;
		parent[x]=y;
		return 1;
	}
};

int main(){
	//input
	int N,M;
	scanf("%d%d",&N,&M);
	vector<pair<int,int>>edges(M);
	unordered_map<int,unordered_set<int>>graph;
	for(int i=0;i<M;i++){
		int A,B;
		scanf("%d%d",&A,&B);
		A--;B--;
		edges.emplace_back(A,B);
		graph[A].insert(B);
		graph[B].insert(A);
	}
	vector<int>target(N);
	for(int i=0;i<N;i++)scanf("%d",&target[i]),target[i]--;
	//find triplets
	union_find uf(N);
	for(auto &e:edges){
		for(int i=0;i<N;i++)if(graph[i].find(e.first)!=graph[i].end()&&graph[i].find(e.second)!=graph[i].end()){
			uf.unite(e.first,e.second);
			uf.unite(e.first,i);
			uf.unite(i,e.second);
		}
	}
	//check
	for(int i=0;i<N;i++)if(!uf.same(target[i],i)){puts("NO");return 0;}
	vector<int> t(N);
	for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)if(uf.same(i,j)&&target[i]>target[j])t[uf.root(i)]^=1;
	for(int i=0;i<N;i++)if(t[i]){puts("NO");return 0;}
	puts("YES");
}