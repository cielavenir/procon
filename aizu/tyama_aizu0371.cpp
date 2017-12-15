#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int n,r=0;
	scanf("%d",&n);
	vector<int>v(n);
	for(int i=0;i<n;i++)scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	set<int>se;
	for(int i=1;i*i<=v[n-1];i++)if(v[n-1]%i==0)se.insert(i),se.insert(v[n-1]/i);
	for(auto &e:v)r+=*se.lower_bound(e)-e;
	printf("%d\n",r);
}
