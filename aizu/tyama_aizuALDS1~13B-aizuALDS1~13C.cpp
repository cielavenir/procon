#pragma GCC optimize("O3")
#pragma GCC target("arch=corei7-avx")
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define X 4
#define Y 4
typedef char val_t;

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
	template<typename T,size_t N>
	class hash<array<T,N>>{
		public:
		size_t operator()(array<T,N> const &container) const{
			return hash_range(container.begin(),container.end());
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

int manhattan(val_t x1,val_t y1,val_t x2,val_t y2){
	return abs(x1-x2)+abs(y1-y2);
}
int calc(vector<val_t>&v){
	int s=0;
	for(int coor=0;coor<X*Y;coor++){
		if(v[coor]!=0){
			s+=manhattan(coor%X,coor/X,(v[coor]-1)%X,(v[coor]-1)/X);
		}else{
			s+=manhattan(coor%X,coor/X,X-1,Y-1);
		}
	}
	return s;
}
int main(){
	int i=1,start_point;
	vector<val_t>start(X*Y),goal;
	for(;i<X*Y;i++)goal.push_back(i);goal.push_back(0);
	for(i=0;i<X*Y;i++){
		scanf("%d",&start[i]);
		if(start[i]==0)start_point=i;
	}
	if(start==goal){puts("0");return 0;}

	unordered_map<vector<val_t>,pair<val_t,val_t>>mstart,mgoal;
	queue<pair<vector<val_t>,bool> >q;
	mstart[start]=make_pair(start_point,0);
	mgoal[goal]=make_pair(X*Y-1,0);
	q.push(make_pair(start,false));
	q.push(make_pair(goal,true));
	int T=0;
	for(;!q.empty();T++){
		int THRESHOLD=2;
		//if(T>100000){puts("40");break;}
		vector<val_t> v=q.front().first;
		bool f=q.front().second;
		q.pop();
		int val=calc(v);
		unordered_map<vector<val_t>,pair<val_t,val_t> >&m=f?mgoal:mstart;
		unordered_map<vector<val_t>,pair<val_t,val_t> >&m2=f?mstart:mgoal;
		int coor=m[v].first,x=coor%X,y=coor/X;
		int depth=m[v].second;
		if(0<x){
			swap(v[coor],v[coor-1]);
			if(m.find(v)==m.end() && calc(v)<=val+THRESHOLD)m[v]=make_pair(coor-1,depth+1),q.push(make_pair(v,f));
			if(m2.find(v)!=m2.end()){printf("%d\n",m2[v].second+depth+1);return 0;}
			swap(v[coor],v[coor-1]);
		}
		if(x<X-1){
			swap(v[coor],v[coor+1]);
			if(m.find(v)==m.end() && calc(v)<=val+THRESHOLD)m[v]=make_pair(coor+1,depth+1),q.push(make_pair(v,f));
			if(m2.find(v)!=m2.end()){printf("%d\n",m2[v].second+depth+1);return 0;}
			swap(v[coor],v[coor+1]);
		}
		if(0<y){
			swap(v[coor],v[coor-X]);
			if(m.find(v)==m.end() && calc(v)<=val+THRESHOLD)m[v]=make_pair(coor-X,depth+1),q.push(make_pair(v,f));
			if(m2.find(v)!=m2.end()){printf("%d\n",m2[v].second+depth+1);return 0;}
			swap(v[coor],v[coor-X]);
		}
		if(y<Y-1){
			swap(v[coor],v[coor+X]);
			if(m.find(v)==m.end() && calc(v)<=val+THRESHOLD)m[v]=make_pair(coor+X,depth+1),q.push(make_pair(v,f));
			if(m2.find(v)!=m2.end()){printf("%d\n",m2[v].second+depth+1);return 0;}
			swap(v[coor],v[coor+X]);
		}
	}
}
