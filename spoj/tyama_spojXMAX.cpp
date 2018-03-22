#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

const int B=62;
long long solve(vector<long long>&a){
	int idx=0;
	for(int i=B-1;i>=0;i--){
		int maxI=idx;
		long long maxE=-1;
		for(int j=idx;j<a.size();j++){
			if((a[j]&(1LL<<i)) && a[j]>maxE){
				maxE=a[j];
				maxI=j;
			}
		}
		if(maxE<0)continue;
		swap(a[idx],a[maxI]);
		maxI=idx;
		for(int j=0;j<a.size();j++){
			if(j!=maxI && (a[j]&(1LL<<i))){
				a[j]=a[j]^a[maxI];
			}
		}
		idx++;
	}
	long long r=0;
	for(int i=0;i<a.size();i++)r^=a[i];
	return r;
}
int main(){
	int n;
	scanf("%d",&n);
	vector<long long>a(n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	printf("%lld\n",solve(a));
}
