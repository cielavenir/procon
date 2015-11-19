#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

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
	template<typename T,typename A>
	class hash<vector<T,A>>{
		public:
		size_t operator()(vector<T,A> const &container) const{
			return hash_range(container.begin(),container.end());
		}
	};
}

int main(){
	int N;
	scanf("%d",&N);
	vector<char>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	priority_queue<pair<int,vector<char> > >q;
	unordered_map<vector<char>,int>depth;

	q.push(make_pair(0,v));
	int R;
	for(;!q.empty();){
		auto cur=q.top();
		q.pop();
		if(depth.find(cur.second)!=depth.end())continue;
		depth[cur.second]=cur.first;
		bool f=false;
		for(int i=0;i<N-1;i++)for(int j=i+1;j<N;j++){
			if(cur.second[i]>cur.second[j])f=true;
			swap(cur.second[i],cur.second[j]);
			if(depth.find(cur.second)==depth.end())q.push(make_pair(cur.first-cur.second[i]-cur.second[j],cur.second));
			swap(cur.second[i],cur.second[j]);
		}
		if(!f){
			R=-cur.first;
			break;
		}
	}
	printf("%d\n",R);
}