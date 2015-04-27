#include <vector>
#include <cstdio>
using namespace std;
typedef pair<int,long long> pil;
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
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	union_find uf(n);
	vector<pil>edge(m);
	for(int i=0;i<m;i++){
		scanf("%d%lld",&edge[i].first,&edge[i].second);
		edge[i].first--;
		edge[i].second--;
	}
	vector<pil>query(k);
	vector<int>flag(m);
	for(int i=0;i<k;i++){
		int a,b,c;
		scanf("%d",&a);
		if(a){
			scanf("%d%d",&b,&c);
			b--,c--;
			query[i]=make_pair(a,(long long)b<<32|c);
		}else{
			scanf("%d",&b);
			b--;
			query[i]=make_pair(a,b);
			flag[b]=1;
		}
	}
	for(int i=0;i<m;i++)if(!flag[i])uf.unite(edge[i].first,edge[i].second);
	vector<int>result;
	for(int i=k-1;i>=0;i--){
		if(query[i].first){
			int b=query[i].second>>32,c=query[i].second;
			result.push_back(uf.same(b,c));
		}else{
			uf.unite(edge[query[i].second].first,edge[query[i].second].second);
		}
	}
	for(int i=result.size()-1;i>=0;i--)puts(result[i]?"YES":"NO");
}