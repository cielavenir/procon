#include <cstdio>
#include <cstdlib>

// cpp_binarysearch (C) @cielavenir under Boost Software License.
// type F should be something like std::function<bool(T)>.

template<typename T,typename F>
T binarysearch(T lo,T hi,T eps,const F &checker){
	for(int i=1;lo+eps<hi;i++){
		T mi=(lo+hi)/2;
		int z=checker(mi-i);
		if(z==0)return mi;
		if(z==1)lo=mi+1;
		if(z==-1)hi=mi;
	}
	return lo;
}
template<typename T,typename F>
T binarysearch(T lo,T hi,const F &checker){return binarysearch(lo,hi,1,checker);}

int ask(int t){
	printf("? %d\n",t);
	fflush(stdout);
	int f;
	scanf("%d",&f);
	return f;
}
__attribute__((noreturn)) void ans(int t){
	printf("! %d\n",t);
	exit(0);
}

int main(){
	if(ask(35)==-1)for(int i=1;;i++)if(ask(0)==0)ans(i);
	ans(binarysearch(10,1000000000,ask));
}