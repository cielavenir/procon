#include <functional>
#include <vector>

template<typename T,typename F>
T ternarysearch(T lo,T hi,const T eps,const F &predicate){
	for(;lo+eps<hi;){
		T mi=(lo+hi)/2;
		if(predicate(mi)>predicate(mi-eps)){
			hi=mi;
		}else{
			lo=mi;
		}
	}
	return lo;
}
template<typename T,typename F>
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
