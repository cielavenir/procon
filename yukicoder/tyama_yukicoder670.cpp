#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

unsigned long long seed;
int next(){
	seed = seed ^ (seed << 13);
	seed = seed ^ (seed >> 7);
	seed = seed ^ (seed << 17);
	return (seed >> 33);
}

int main(){
	const unsigned int M=2200000000,B=100000;
	int n,q;
	scanf("%d%d%llu",&n,&q,&seed);
	for(int i=0;i<10000;i++)next();
	vector<int>a(n);
	for(int i=0;i<n;i++)a[i]=next();
	sort(a.begin(),a.end());
	vector<vector<int>>bucket(M/B);
	vector<int>bucketsize(M/B);
	for(auto &e:a)bucket[e/B].push_back(e);
	bucketsize[0]=bucket[0].size();
	for(int i=1;i<bucketsize.size();i++)bucketsize[i]=bucketsize[i-1]+bucket[i].size();
	long long ret=0;
	for(int i=0;i<q;i++){
		int x=next();
		ret^=(long long)i*((x/B<1 ? 0 : bucketsize[x/B-1])+distance(bucket[x/B].begin(),lower_bound(bucket[x/B].begin(),bucket[x/B].end(),x)));
	}
	printf("%lld\n",ret);
}
