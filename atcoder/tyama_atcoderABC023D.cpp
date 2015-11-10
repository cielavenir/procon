#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

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

bool chk(long long x,vector<pair<long long,long long> >&balloon){
	vector<long long>z(balloon.size());
	for(int i=0;i<balloon.size();i++){
		if(x-balloon[i].first<0)return false;
		z[i]=(x-balloon[i].first)/balloon[i].second;
	}
	sort(z.begin(),z.end());
	for(int i=0;i<z.size();i++)if(z[i]<i)return false;
	return true;
}

int main(){
	int N;
	scanf("%d",&N);
	vector<pair<long long,long long> >balloon(N);
	long long lo=0,hi=0;
	for(int i=0;i<N;i++){
		long long h,s;
		scanf("%lld%lld",&h,&s);
		balloon[i]=make_pair(h,s);
		hi=max(hi,h+s*N);
	}
	printf("%lld\n",binarysearch(lo,hi,[&](long long mi){
		return chk(mi,balloon);
	}));
}