#include <vector>
#include <numeric>
#include <cstdio>
using namespace std;
int main(){
	int L,K;
	for(;~scanf("%d%d",&L,&K)&&L&&K;){
		vector<long long>a0(L+K),a1(L+K);
		a1[0]=1;
		for(int i=0;i<L;i++){
			a0[i+1]+=a1[i];
			a0[i+K]+=a1[i];
			a1[i+1]+=a0[i];
		}
		printf("%lld\n",accumulate(a0.begin()+1,a0.begin()+L+1,0LL));
	}
}
