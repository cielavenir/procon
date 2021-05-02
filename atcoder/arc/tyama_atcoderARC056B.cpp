#include<vector>
#include<cstdio>
using namespace std;
class union_find{
public:
	vector<int>P;
	int R(int a){return P[a]==a?a:P[a]=R(P[a]);}
	union_find(int n):P(n){for(int i=0;i<n;i++)P[i]=i;}
	void unite(int a,int b){int x=R(a),y=R(b);P[y]=x;}
};
int main(){
	int N,M,S,i=0,x,y;
	scanf("%d%d%d",&N,&M,&S);
	vector<vector<int>>E(N+1);union_find uf(N+1);
	for(;i++<M;E[min(x,y)].push_back(max(x,y)))scanf("%d%d",&x,&y);
	for(i=N+1;--i;E[i]={uf.R(i)==uf.R(S)})for(auto &e:E[i])uf.unite(i,e);
	for(i=0;++i<=N;)E[i]==E[S]&&printf("%d\n",i);
}