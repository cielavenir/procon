#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;
int main(){
	int n,i;
	scanf("%d",&n);
	vector<int>v(n);
	for(i=0;i<n;i++)scanf("%d",&v[i]);
	sort(v.begin(),v.end(),greater<int>());
	for(i=0;i<n&&v[i]>=i+1;i++);
	printf("%d\n",i);
}
