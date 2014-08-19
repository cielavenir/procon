#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
main(){int n,m,a,b;for(;scanf("%d",&n),n;puts(m>150?"NG":"OK")){
vector<pair<int,int> >v;
for(;n;n--)scanf("%d%d%d",&m,&a,&b),v.push_back(make_pair(a,m)),v.push_back(make_pair(b,-m));
sort(v.begin(),v.end());
for(m=n=0;n<v.size();n++)if((m+=v[n].second)>150)break;
}}