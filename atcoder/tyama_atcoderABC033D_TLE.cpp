#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

long long sq(long long n){return n*n;}
int main(){
	int N;
	scanf("%d",&N);
	vector<pair<long long,long long> >v(N);
	for(int i=0;i<N;i++)scanf("%lld%lld",&v[i].first,&v[i].second);
	long long r0=0,r1=0,r2=0;
	for(int i=0;i<N-2;i++)for(int j=i+1;j<N-1;j++){
		long long x=sq(v[i].first-v[j].first)+sq(v[i].second-v[j].second);
		for(int k=j+1;k<N;k++){
			long long a[3]={
				x,
				sq(v[j].first-v[k].first)+sq(v[j].second-v[k].second),
				sq(v[k].first-v[i].first)+sq(v[k].second-v[i].second),
			};
			long long m=*max_element(a,a+3);
			long long n=a[0]+a[1]+a[2]-m;
			if(m<n){
				r0++;
			}else if(m==n){
				r1++;
			}else{
				r2++;
			}
		}
	}
	printf("%lld %lld %lld\n",r0,r1,r2);
}