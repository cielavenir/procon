#include <vector>
#include <unordered_map>
#include <cstdio>
using namespace std;

namespace std{
	template<typename I>
	class hash<pair<I,I>>{
		public:
		size_t operator()(const pair<I,I> &p) const {return hash<long long>() (((long long)(p.first))<<32|p.second);}
	};
}

unordered_map<pair<int,int>,int>m;
unordered_map<pair<int,int>,long long>memo;
vector<int> f;
int N;

long long dfs(int i,int j){
	long long r=0;
	pair<int,int> p=make_pair(i,j);
	if(memo.find(p)!=memo.end())return memo[p];
	if(i==j)return !f[i];
	for(int k=0;k<N;k++)if(m.find({i,k})!=m.end())r+=dfs(k,j)*m[{i,k}];
	return memo[p]=r;
}
int main(){
	int M,P,Q,R;
	scanf("%d%d",&N,&M);
	f.resize(N);
	for(;M--;){
		scanf("%d%d%d",&P,&Q,&R);
		m[{R-1,P-1}]=Q;
		f[R-1]=1;
	}
	for(int i=0;i<N-1;i++)printf("%lld\n",dfs(N-1,i));
}