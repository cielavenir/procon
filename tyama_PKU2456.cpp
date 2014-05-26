#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

bool ok(long long M,int N,int C,vector<long long>&v){
	long long prev=v[0];
	int ret=1;
	for(int i=1;i<N;i++)if(v[i]-prev>=M)prev=v[i],ret++;
	return ret>=C;
}
int main(){
	int N,C;
	scanf("%d%d",&N,&C);
	vector<long long>v(N);
	for(int i=0;i<N;i++)scanf("%lld",&v[i]);
	sort(v.begin(),v.end());
	long long l=0,h=1LL<<50;
	for(;l+1<h;){
		long long m=(l+h)/2;
		if(ok(m,N,C,v))l=m;else h=m;
	}
	printf("%lld\n",l);
}