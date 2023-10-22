// https://github.com/cielavenir/cpp_libraries/blob/master/binarysearch/binarysearch.hpp
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

#include <stdio.h>
#include <math.h>
#include <vector>
#define EPS 1e-6
#define zero(n)(fabs(n)<EPS)
int main(){
	int N,a,b,c,d,L,R,p,q,r,D;
	for(scanf("%d",&N);N--;){
	scanf("%d%d%d%d",&a,&b,&c,&d);//fx=ax3+bx2+cx+d
	if(a<0)a=-a,b=-b,c=-c,d=-d;   //won't lose generality
	p=3*a,q=2*b,r=c,D=q*q-4*p*r;  //f'x=3ax2+2bx+c D: f'x=0?
	std::vector<double> v;
	auto F=[&](double x){
		return a*x*x*x+b*x*x+c*x+d;
	};
	if(D>0){
		double x1=(-q-sqrt(D))/p/2,x2=(-q+sqrt(D))/p/2;
		double y1=F(x1);
		double y2=F(x2);
		if(zero(y1)){
			v.push_back(x1);
			v.push_back(x1);
			v.push_back(binarysearch(x2,1e9,[&](double x){
				return F(x)>=0;
			}));
		}else if(zero(y2)){
			v.push_back(binarysearch(-1e9,x1,[&](double x){
				return F(x)>=0;
			}));
			v.push_back(x2);
			v.push_back(x2);
		}else if(y1*y2>0){
			if(y1<0){
				v.push_back(binarysearch(x2,1e9,[&](double x){
					return F(x)>=0;
				}));
			}
			else{
				v.push_back(binarysearch(-1e9,x1,[&](double x){
					return F(x)>=0;
				}));
			}
		}else{
			v.push_back(binarysearch(-1e9,x1,[&](double x){
				return F(x)>=0;
			}));
			v.push_back(binarysearch(x1,x2,[&](double x){
				return F(x)<=0;
			}));
			v.push_back(binarysearch(x2,1e9,[&](double x){
				return F(x)>=0;
			}));
		}
	}else if(D==0){
		double x=(-q)/p/2;
		double y=F(x);
		if(zero(y)){
			v.push_back(x);
			v.push_back(x);
			v.push_back(x);
		}else if(y<0){
			v.push_back(binarysearch(x,1e9,[&](double x){
				return F(x)>=0;
			}));
		}else{
			v.push_back(binarysearch(-1e9,x,[&](double x){
				return F(x)>=0;
			}));
		}
	}else{
		v.push_back(binarysearch(-1e9,1e9,[&](double x){
			return F(x)>=0;
		}));
	}
	L=0,R=0;
	for(auto &e:v){
		if(!zero(e)){
			if(e<0)L++;
			else R++;
		}
	}
	printf("%d %d\n",R,L);
	}
}
