#include <cstdio>

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
	printf("! %d\n",binarysearch(1,1000000000,[&](int t){
		printf("? %d\n",t);
		fflush(stdout);
		int f;
		scanf("%d",&f);
		return f;
	}));
}