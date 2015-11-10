#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
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

int main(){
	int L,N,K;
	scanf("%d%d%d",&L,&N,&K);
	vector<int> x(N+1);
	x[N]=L;
	for(int i=0;i<N;i++)scanf("%d",&x[i]);
	for(int i=0;i<N;i++)x[i]=x[i+1]-x[i];
	double ans=2*binarysearch(0.0,(double)L,[&](double mid){
		double sum=0;
		for(int i=0;i<N;i++)sum+=floor(x[i]/mid);
		return sum<=K;
	});
	sort(x.begin(),x.begin()+N);
	int r=binarysearch(0,N-1,[&](int m){
		long long sum=0;
		for(int i=0;i<N;i++)sum+=(x[i]-1)/x[m];
		return sum<=K;
	});
	double t=x[r];
	x[r]=x[N-1];
	N--;
	ans=min(ans,t+binarysearch(0.0,(double)L,[&](double mid){
		double sum=0;
		for(int i=0;i<N;i++)sum+=floor(x[i]/mid);
		return sum<=K;
	}));

	printf("%f\n",ans/2);
}