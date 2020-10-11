#include <functional>
#include <vector>
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
template<typename T,typename F=std::function<T(T)>>
T ternarysearch(T lo,T hi,const F &predicate){return ternarysearch(lo,hi,(T)1,predicate);}

int Q(const std::vector<int>&v){
	printf("?");
	for(auto &e:v)printf(" %d",e);
	puts("");
	fflush(stdout);
	int n;
	scanf("%d",&n);
	return n;
}

int main(){
	std::vector<int>v(3);
	for(int i=0;i<3;i++)v[i]=ternarysearch(-150,151,[&](int n){
		std::vector<int>a(3);
		a[i]=n;
		return Q(a);
	});
	printf("!");
	for(auto &e:v)printf(" %d",e);
	puts("");
}
