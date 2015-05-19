#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int N;
	long long x;
	scanf("%d%lld",&N,&x);
	vector<long long>v(N);
	for(int i=0;i<N;i++)scanf("%lld",&v[i]);
	sort(v.begin(),v.end());

	int ret=N;
	long long s=x;
	for(int i=0;i<N;i++){
		auto it=upper_bound(v.begin(),v.end(),s);
		if(it!=v.end()){
			int dist=distance(v.begin(),it);
			//cut [i,dist)
			ret=min(ret,dist-i);
		}
		s+=v[i];
	}
	printf("%d\n",ret==N?-1:ret);
}
