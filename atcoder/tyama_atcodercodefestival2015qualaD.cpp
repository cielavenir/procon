#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
 
// cpp_binarysearch (C) @cielavenir under Boost Software License.
// type F should be something like std::function<bool(T)>.
 
template<typename T,typename F>
T binarysearch(T lo,T hi,T eps,const F &checker){
	for(;lo+eps<hi;){
		T mi=(lo+hi)/2;
		if(checker(mi)){
			hi=mi;
		}else{
			lo=mi;
		}
	}
	return lo;
}
template<typename T,typename F>
T binarysearch(T lo,T hi,const F &checker){return binarysearch(lo,hi,(T)1,checker);}
 
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	vector<int>X(M);
	for(int i=0;i<M;i++)scanf("%d",&X[i]);

#if 0
	//この挿入句によりbinarysearch()の上限をNに変更できる。
	//故に(lo+hi)/2でのオーバーフローをint型でも回避できる。
	if(M==1){
		printf("%d\n",N-1+min(X[0]-1,N-X[M-1]));
		return 0;
	}
#endif

	printf("%lld\n",1+binarysearch(-1LL,2LL*N,[&](long long n)->bool{
		int cur=1;
		for(auto &e:X){
			if(cur>e)cur=e;
			int back=e-cur;
			if(back>n)return false;
			cur=1+e+max(n-back*2,(n-back)/2);
		}
		return cur>N;
	}));
}