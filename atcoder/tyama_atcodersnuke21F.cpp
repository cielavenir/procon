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
	int L,N,K;
	scanf("%d%d%d",&L,&N,&K);
	vector<int> x(N+1);
	x[N]=L;
	for(int i=0;i<N;i++)scanf("%d",&x[i]);
	for(int i=0;i<N;i++)x[i]=x[i+1]-x[i];
	double ans=2*binarysearch(0.0,(double)L,1e-7,[&](double mid){
		long long sum=0;
		for(int i=0;i<N;i++)sum+=x[i]/mid;
		return sum>K;
	});

	sort(x.begin(),x.begin()+N);
	int r=binarysearch(-1,N-1,[&](int m){
		long long sum=0;
		for(int i=0;i<N;i++)sum+=(x[i]-1)/x[m];
		return sum>K;
	})+1;
	double t=x[r];
	x[r]=x[N-1];
	N--;
	ans=min(ans,t+binarysearch(0.0,(double)L,1e-7,[&](double mid){
		long long sum=0;
		for(int i=0;i<N;i++)sum+=x[i]/mid;
		return sum>K;
	}));

	printf("%f\n",ans/2);
}