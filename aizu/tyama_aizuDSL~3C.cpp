#include <vector>
#include <cstdio>
using namespace std;
int main(){
	int N,Q;
	long long q;
	scanf("%d%d",&N,&Q);
	vector<long long>v(N);
	for(int i=0;i<N;i++)scanf("%lld",&v[i]);
	for(;Q--;){
		scanf("%lld",&q);
		long long s=0,r=0;
		int start=0,stop=0;
		for(;;){
			for(;stop<N&&s+v[stop]<=q;stop++)s+=v[stop];
			for(;start<N&&s>q;start++)s-=v[start];
			if(start==N)break;
			r+=stop-start;
			if(start<N)s-=v[start++];
		}
		printf("%lld\n",r);
	}
}
