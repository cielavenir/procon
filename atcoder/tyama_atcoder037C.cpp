#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

// cpp_binarysearch (C) @cielavenir under Boost Software License.
// type F should be something like std::function<bool(T)>.

template<typename T,typename F>
T binarysearch(T lo,T hi,T eps,const F &checker){
	for(;lo+eps<hi;){
		T mi=lo+(hi-lo)/2;
		if(checker(mi)){
			lo=mi;
		}else{
			hi=mi;
		}
	}
	return lo;
}
template<typename T,typename F>
T binarysearch(T lo,T hi,const F &checker){return binarysearch(lo,hi,(T)1,checker);}

int perform(vector<int>&a,vector<int>&b,long long K){
	int r=0,d=a.size();
	//for(auto &e:a)r+=distance(b.begin(),upper_bound(b.begin(),b.end(),K/e));
	for(auto &e:a){for(;d&&b[d-1]>K/e;d--);r+=d;}
	return r;
}

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	vector<int>a(N),b(N);
	for(int i=0;i<N;i++)scanf("%d",&a[i]);
	for(int i=0;i<N;i++)scanf("%d",&b[i]);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	printf("%lld\n",1+binarysearch(1LL,1LL<<61,[&](long long mi){
		return perform(a,b,mi)<K;
	}));
}