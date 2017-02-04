#include <vector>
#include <unordered_map>
#include <cstdio>
using namespace std;

namespace std{
	template<typename T>
	inline void hash_combine(size_t& seed, T const& v){
		//if(sizeof(size_t)==4){
			seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
		//}else if(sizeof(size_t)==8){
		//	seed ^= hash<T>()(v) + 0x9e3779b97f4a7c15 + (seed<<6) + (seed>>2);
		//}else{
		//	abort();
		//}
	}
	template<typename It>
	inline size_t hash_range(It first, It last){
		size_t seed=0;
		hash_range(seed,first,last);
		return seed;
	}
	template<typename It>
	inline void hash_range(size_t& seed, It first, It last){
		for(;first!=last;++first)hash_combine(seed, *first);
	}
	template<typename T,typename A>
	class hash<vector<T,A>>{
		public:
		size_t operator()(vector<T,A> const &container) const{
			return hash_range(container.begin(),container.end());
		}
	};
}

int main(){
	const int M=1000000007;
	int n,m;
	scanf("%d%d",&n,&m);
	vector<vector<int>>h(m);
	for(int i=0;i<n;i++){
		int c,x;
		for(scanf("%d",&c);c--;){
			scanf("%d",&x);h[x-1].push_back(i);
		}
	}
	vector<int>f(m+1);f[0]=1;
	unordered_map<vector<int>,int>g;
	for(int i=0;i<m;i++){
		f[i+1]=f[i]*(long long)(i+1)%M;
		g[h[i]]++;
	}
	long long r=1;
	for(auto &e:g)r=r*f[e.second]%M;
	printf("%lld\n",r);
}
