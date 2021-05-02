#include <functional>
#include <cmath>
#include <cstdio>
template<typename T,typename F>
T ternarysearch(T lo,T hi,const T eps,const F &predicate){
	T r=lo;
	for(;lo<hi+eps;){
		T mi1=lo+(hi-lo)/3;
		T mi2=hi-(hi-lo)/3;
		if(predicate(mi1)<predicate(mi2)){
			hi=mi2-eps;
		}else{
			r=mi1;
			lo=mi1+eps;
		}
	}
	return r;
}

template<typename F=std::function<double(double)>>
double ternarysearch(double _lo,double _hi,const F &predicate){
	long long lo;
	if(_lo<0)_lo=-_lo,lo=-*(long long*)(&_lo);else lo=*(long long*)(&_lo);
	long long hi;
	if(_hi<0)_hi=-_hi,hi=-*(long long*)(&_hi);else hi=*(long long*)(&_hi);
	long long _r=ternarysearch(lo,hi,1LL,[&](long long _mi){
		double mi;
		if(_mi<0)_mi=-_mi,mi=-*(double*)(&_mi);else mi=*(double*)(&_mi);
		return predicate(mi);
	});
	double r;
	if(_r<0)_r=-_r,r=-*(double*)(&_r);else r=*(double*)(&_r);
	return r;
}

int main(){
	double p;
	scanf("%lf",&p);
	auto f=[&](double x){
		return x+p*pow(2,-(x/1.5));
	};
	printf("%.9f\n",f(ternarysearch(0.0,10000.0,f)));
}
