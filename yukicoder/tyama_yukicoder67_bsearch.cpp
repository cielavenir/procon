#include <vector>
#include <cstdio>

// cpp_binarysearch (C) @cielavenir under Boost Software License.
// https://github.com/cielavenir/cpp_libraries/tree/master/binarysearch
// returns the smallest value satisfying the predicate.

#include <functional>
template<typename T,typename F=std::function<bool(T)>>
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
template<typename T,typename F=std::function<bool(T)>>
T binarysearch(T lo,T hi,const F &predicate){return binarysearch(lo,hi,(T)1,predicate);}

template<typename F=std::function<bool(double)>>
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
	int n;
	long long k;
	scanf("%d",&n);
	std::vector<double>v(n);
	for(int i=0;i<n;i++){
		scanf("%lf",&v[i]);
	}
	scanf("%lld",&k);
	printf("%.9f\n",binarysearch(0.0,1e9,[&](double h){
		long long _n=0;
		for(int i=0;i<n;i++){
			double x=v[i]/h;
			if(x>=k)return false;
			_n+=x;
		}
		return _n<k;
	}));
}
