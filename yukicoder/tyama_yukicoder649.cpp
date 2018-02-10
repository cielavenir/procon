#include <deque>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	deque<long long>v;
	int Q,K,q;
	long long n;
	scanf("%d%d",&Q,&K);
	for(;Q--;){
		scanf("%d",&q);
		if(q==1){
			scanf("%lld",&n);
			auto it=lower_bound(v.begin(),v.end(),n);
			v.insert(it,n);
		}else{
			if(v.size()<K){
				puts("-1");
			}else{
				printf("%lld\n",v[K-1]);
				v.erase(v.begin()+K-1);
			}
		}
	}
}
