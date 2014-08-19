#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int n,x,i,j;
	scanf("%d",&n);
	vector<int>a(n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	vector<vector<long long> >v(2);
	v[0].resize(n+1);
	for(i=1;i<=n;i++)v[0][i]=v[0][i-1]+a[i-1];
	sort(a.begin(),a.end());
	v[1].resize(n+1);
	for(i=1;i<=n;i++)v[1][i]=v[1][i-1]+a[i-1];
	scanf("%d",&n);
	for(;n--;){
		scanf("%d%d%d",&x,&i,&j);
		printf("%lld\n",v[x-1][j]-v[x-1][i-1]); //
	}
}