#include <unordered_map>
#include <cstdio>

//本実装はboostによる.
namespace std{
	template<typename T>
	inline void hash_combine(size_t& seed, T const& v){
		seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
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
	template<typename A,typename B>
	class hash<pair<A,B>>{
		public:
		size_t operator()(pair<A,B> const &p) const{
			size_t seed=0;
			hash_combine(seed,p.first);
			hash_combine(seed,p.second);
			return seed;
		}
	};
}

int main(){
	int N,M;
	long long x;
	std::unordered_map<std::pair<long long,int>,int>m;
	scanf("%d%d",&N,&M);
	for(;N--;)scanf("%lld",&x),m[{x,0}]++;
	for(;M--;)scanf("%lld",&x),printf(M?"%d ":"%d\n",m[{x,0}]);
}