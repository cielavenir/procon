#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{0,-1},{0,1},{-1,0},{1,0}
};

long long bfs(const vector<string>&v,const pii &start,const pii &goal,long long cost){
	queue<pii>q;
	map<pii,long long>depth;
	depth[start]=0;
	for(q.push(start);!q.empty();){
		pii cur=q.front();q.pop();
		for(auto d:D){
			pii nxt={cur.first+d.x,cur.second+d.y};
			if(
				0<=nxt.first&&nxt.first<v[0].size() &&
				0<=nxt.second&&nxt.second<v.size() &&
				(depth.find(nxt)==depth.end() || depth[nxt]>depth[cur]+(v[nxt.second][nxt.first]=='#'?cost:1))
			){
				q.push(nxt);
				depth[nxt]=depth[cur]+(v[nxt.second][nxt.first]=='#'?cost:1);
			}
		}
	}
	return depth[{goal.first,goal.second}];
}

// cpp_binarysearch (C) @cielavenir under Boost Software License.
// returns the smallest value satisfying the predicate.
// type F should be something like std::function<bool(T)>.

template<typename T,typename F>
T binarysearch(T lo,T hi,const T eps,const F &predicate){
	T r=hi+eps;
	for(;lo<hi+eps;){
		T mi=eps!=1||(lo<0)==(hi<0) ? lo+(hi-lo)/2 : (lo<-hi) ? -((-lo-hi-1)/2+1) : (lo+hi)/2;
		if(predicate(mi)){
			r=mi;
			hi=mi-eps;
		}else{
			lo=mi+eps;
		}
	}
	return r;
}
template<typename T,typename F>
T binarysearch(T lo,T hi,const F &predicate){return binarysearch(lo,hi,(T)1,predicate);}

template<typename F>
double binarysearch(double _lo,double _hi,const F &predicate){
	long long lo;
	if(_lo<0)_lo=-_lo,lo=-*(long long*)(&_lo);else lo=*(long long*)(&_lo);
	long long hi;
	if(_hi<0)_hi=-_hi,hi=-*(long long*)(&_hi);else hi=*(long long*)(&_hi);
	long long _r=binarysearch(lo,hi,1LL,[&](long long _mi){
		double mi;
		if(_mi<0)_mi=-_mi,mi=-*(double*)(&_mi);else mi=*(double*)(&_mi);
		return predicate(mi);
	});
	double r;
	if(_r<0)_r=-_r,r=-*(double*)(&_r);else r=*(double*)(&_r);
	return r;
}

int main(){
	int H,W;
	long long T;
	cin>>H>>W>>T;
	vector<string>v(H);
	pii start,goal;
	for(int i=0;i<H;i++){
		cin>>v[i];
		for(int j=0;j<W;j++){
			if(v[i][j]=='S')start={j,i};
			if(v[i][j]=='G')goal={j,i};
		}
	}
	long long lo=1,hi=T;
	cout<<binarysearch(1LL,T,[&](long long me){
		return bfs(v,start,goal,me)>T;
	})-1<<endl;
}