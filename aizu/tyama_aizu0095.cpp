#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
main(){
	int n,a,b;
	vector<pair<int,int> >v;
	for(scanf("%d",&n);n--;v.push_back(make_pair(-b,a)))scanf("%d%d",&a,&b);
	sort(v.begin(),v.end());
	printf("%d %d\n",v[0].second,-v[0].first);
}