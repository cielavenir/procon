#include <deque>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	deque<long long> v;
	int siz=0;
	long long n;
	char mode[]="a";
	for(scanf("%lld",&n);~scanf("%s%lld",mode,&n);){
		auto it=lower_bound(v.begin(),v.end(),n);
		if(*mode=='a'){
			v.insert(it,n);
			siz++;
		}else{
			if(it==v.end()||*it!=n){
				puts("Wrong!");
				continue;
			}
			v.erase(it);
			siz--;
		}
		if(siz==0){
			puts("Wrong!");
		}else if(siz&1){
			printf("%lld\n",v[siz/2]);
		}else{
			n=v[siz/2-1]+v[siz/2];
			if(n&1){
				if(n==-1)puts("-0.5");
				else printf("%lld.5\n",n/2);
			}else{
				printf("%lld\n",n/2);
			}
		}
	}
}