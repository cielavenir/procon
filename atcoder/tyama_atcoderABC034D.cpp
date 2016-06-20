#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
using namespace std;
typedef pair<double,double> pdd;

/// C++ libraries
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

#ifdef BOOST
#include <boost/range.hpp>
#define make_range boost::irange
#else
#include <iterator>
template<typename T>
class range{
public:
	struct iterator{
		const T a,b;
		T p;
		const long long d; //because T might be unsigned.
		iterator(T _a,T _b,T _p,long long _d=1):a(_a),b(_b),p(_p),d(_d){}

	public:
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef std::ptrdiff_t difference_type;
		typedef std::random_access_iterator_tag iterator_category;

		//copy
		iterator(const iterator &other):a(other.a),b(other.b),p(other.p),d(other.d){}
		iterator operator=(const iterator &other){return iterator(other.a,other.b,other.p,other.d);}

		//advance
		iterator& operator+=(T n){p+=n*d;return *this;}
		iterator& operator-=(T n){return *this+=(-n);}
		iterator& operator++(){return *this+=1;}
		iterator& operator--(){return *this-=1;}
		iterator operator+(T n) const{return iterator(a,b,p+n*d);}
		iterator operator-(T n) const{return *this+(-n);}

		//difference
		T operator-(const iterator& other) const{return p-other.p;}

		//equality
		bool operator==(const iterator& other) const{return a==other.a && b==other.b && d==other.d && p==other.p;}
		bool operator!=(const iterator& other) const{return !(*this==other);}

		//compare
		bool operator<(const iterator& other) const{return a==other.a && b==other.b && d==other.d && p*d<other.p*d;}
		bool operator>(const iterator& other) const{return a==other.a && b==other.b && d==other.d && p*d>other.p*d;}

		//reference
		const T& operator*() const{return p;}
	};

private:
	const T a,b;
	T siz;
	long long d;
public:
	range(T _a,T _b,long long _d=1):a(_a),b(_b){
		d=_d;
		if(d==0)d=1; //
		siz=( (d>0?(b-a):(a-b)) - 1)  / (d>0?d:-d);
	}

	T operator[](T n){return a+n*d;}
	iterator begin(){return iterator(a,a+d*siz,a,d);}
	iterator end(){return iterator(a,a+d*siz,a+d*(siz+1),d);}
	iterator rbegin(){return iterator(b-d*siz,b,b,-1*d);}
	iterator rend(){return iterator(b-d*siz,b,b-d*(siz+1),-1*d);}
	T size(){return siz+1;}
};
template<typename T>
range<T> make_range(T a,T b,long long d=1){return range<T>(a,b,d);}
#endif
///end

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	vector<pdd>v(N);
	for(auto &i:range<int>(0,N))scanf("%lf%lf",&v[i].first,&v[i].second);
	printf("%f\n",binarysearch(0.0,100.0,[&](double d){
		vector<double>w(N);
		for(auto &i:range<int>(0,N))w[i]=v[i].first*(v[i].second-d);
		sort(w.begin(),w.end(),greater<double>());
		return accumulate(w.begin(),w.begin()+K,0.0)<0;
	}));
}