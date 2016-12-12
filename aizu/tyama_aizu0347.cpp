#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<int>a(n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	vector<vector<int>>v={
		{2,3,0,1},{0,3,1,2}
	};
	for(int i=3;i<n;i++)v.push_back({0,1,i-1,i});
	vector<double>r;
	transform(v.begin(),v.end(),back_inserter(r),[&a](const vector<int> &e)->double{
		return (a[e[0]]+a[e[1]])*1.0/(a[e[2]]-a[e[3]]);
	});
	printf("%f\n",*max_element(r.begin(),r.end()));
}
