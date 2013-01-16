#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int i,n,a,b;
	for(;scanf("%d",&n),n;puts(i==n?"Yes":"No")){
		vector<pair<int,int> >v;
		for(i=0;i<n;i++)scanf("%d%d",&a,&b),v.push_back(make_pair(b,a));
		sort(v.begin(),v.end());
		for(a=i=0;i<n;i++)if(a+=v[i].second,a>v[i].first)break;
	}
}