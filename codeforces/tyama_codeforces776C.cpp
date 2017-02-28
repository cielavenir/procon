#include <vector>
#include <map>
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
	template<typename T,typename A>
	class hash<vector<T,A>>{
		public:
		size_t operator()(vector<T,A> const &container) const{
			return hash_range(container.begin(),container.end());
		}
	};
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	vector<long long>x(n+1);
	x[0]=0;
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]),x[i]+=x[i-1];
	long long r=0;
	map<long long,int>m; //unordered_map not good here...
	for(int i=n;i>=0;i--){
		long long cur=1;
		for(;cur<1e15;){
			if(m.find(x[i]+cur)!=m.end())r+=m[x[i]+cur];
			cur*=k;
			if(cur==1)break;
		}
		m[x[i]]++;
	}
	printf("%lld\n",r);
}
