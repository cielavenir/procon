#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	vector<pair<int,int> >v;
	int n,s,r;
	for(;scanf("%d,%d",&n,&s),n;)v.push_back(make_pair(-s,n));
	sort(v.begin(),v.end());
	map<int,int>m;
	r=1,m[v[0].second]=r,s=v[0].first;
	for(n=1;n<v.size();m[v[n].second]=r,n++)if(s<v[n].first)s=v[n].first,r++;
	for(;~scanf("%d",&n);)printf("%d\n",m[n]);
}