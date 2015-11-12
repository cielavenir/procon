#include <queue>
#include <set>
#include <unordered_set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;

/// pair<int,int> hasher
namespace std{
	template<typename I>
	class hash<pair<I,I>>{
		public:
		size_t operator()(const pair<I,I> &p) const {return hash<long long>() (((long long)(p.first))<<32|p.second);}
	};
}

double solve(const vector<pii> &a){
	set<int>ys;
	for(auto &e:a)ys.insert(e.second);
	int n=a.size();
	vector<double>mx,my;
	mx.reserve(n*2);
	my.reserve(n*2);
	for(int i=0;i<n;i++){
		mx.push_back(a[i].first);
		my.push_back(a[i].second);
		if(i==n-1)continue;
		//辺上の点でy座標が集合ysに含まれるもの
		if(a[i].second<a[i+1].second){ //頂点iは谷である
			for(auto it=ys.begin();it!=ys.end();++it){
				if(a[i].second<*it && *it<a[i+1].second){
					double dy=a[i+1].second-a[i].second;
					double dx=(a[i+1].first-a[i].first)/dy*(*it-a[i].second);
					mx.push_back(a[i].first+dx);
					my.push_back(*it);
				}
			}
		}else{ //頂点iは山である
			for(auto it=ys.end();it--!=ys.begin();){
				if(a[i+1].second<*it && *it<a[i].second){
					double dy=a[i+1].second-a[i].second;
					double dx=(a[i+1].first-a[i].first)/dy*(*it-a[i].second);
					mx.push_back(a[i].first+dx);
					my.push_back(*it);
				}
			}
		}
	}
	int m=mx.size();
	priority_queue<pair<double,pii>>q;
	unordered_set<pii>se;
	q.push({0,{0,m-1}});
	for(;!q.empty();){
		double c=q.top().first;
		int l=q.top().second.first;
		int r=q.top().second.second;
		q.pop();
		if(se.find({l,r})!=se.end())continue;
		se.insert({l,r});
		if(l==r)return -c;
		for(int i=-1;i<2;i++)for(int j=-1;j<2;j++){
			if((i||j) && 0<=l+i&&l+i<m && 0<=r+j&&r+j<m && fabs(my[l+i]-my[r+j])<1e-9)
				q.push({c-hypot(mx[l]-mx[l+i],my[l]-my[l+i])-hypot(mx[r]-mx[r+j],my[r]-my[r+j]),{l+i,r+j}});
		}
	}
	abort();
}

int main(){
	int N,x,y;
	for(;scanf("%d",&N),N;){
		vector<pii>a(N);
		for(int i=0;i<N;i++)scanf("%d%d",&a[i].first,&a[i].second);
		printf("%f\n",solve(a));
	}
}