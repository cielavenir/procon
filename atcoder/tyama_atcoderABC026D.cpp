#include <cstdio>
#include <cmath>

// cpp_binarysearch (C) @cielavenir under Boost Software License.
// type F should be something like std::function<bool(T)>.

template<typename T,typename F>
T binarysearch(T lo,T hi,T eps,const F &checker){
	for(;lo+eps<hi;){
		T mi=(lo+hi)/2;
		if(checker(mi)){
			lo=mi;
		}else{
			hi=mi;
		}
	}
	return lo;
}
template<typename T,typename F>
T binarysearch(T lo,T hi,const F &checker){return binarysearch(lo,hi,1,checker);}

int main(){
	int A,B,C;
	scanf("%d%d%d",&A,&B,&C);
	printf("%.11f\n",binarysearch(0.0,1000.0,1e-11,[&](double t){
		double n=A*t+B*sin(C*t*M_PI);
		return n<100;
	}));
}