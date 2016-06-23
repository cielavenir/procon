#include<vector>
#include<tuple>
#include<algorithm>
#include<cstdio>
using namespace std;
class union_find{
public:
	vector<int>P,S;
	int R(int a){return P[a]==a?a:P[a]=R(P[a]);}
	union_find(int n):P(n),S(n){for(int i=0;i<n;i++)P[i]=i,S[i]=1;}
	void unite(int a,int b){int x=R(a),y=R(b);if(x!=y)P[x]=y,S[y]+=S[x];}
};
int main(){
	vector<tuple<int,int,int,int>>v;int N,M,x,y,z,i=-1;
	scanf("%d%d",&N,&M);
	for(;++i<M;v.push_back({-z,1,x-1,y-1}))scanf("%d%d%d",&x,&y,&z);
	scanf("%d",&M);
	for(i=-1;++i<M;v.push_back({-z,0,x-1,i}))scanf("%d%d",&x,&z);
	sort(v.begin(),v.end());
	vector<int>r(M);union_find uf(N);
	for(auto&e:v)get<1>(e)?uf.unite(get<2>(e),get<3>(e)):(void)(r[get<3>(e)]=uf.S[uf.R(get<2>(e))]);
	for(auto &e:r)printf("%d\n",e);
}