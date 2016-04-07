#include <cstdio>

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

int main(){
	int t;
	long long n,x,i;
	for(scanf("%d",&t);t--;){
		scanf("%lld",&n);
		printf("%lld\n",binarysearch(5LL,1LL<<62,[&](long long i){
			long long r=0,d=5;
			for(;d<=i;d*=5)r+=i/d;
			return r>=n;
		}));
	}
}