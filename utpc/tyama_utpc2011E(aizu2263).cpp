#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
main(){int i=0,n,a,b,s=0;
vector<pair<int,int> >v;
for(scanf("%d",&n);i<n;i++)scanf("%d%d",&a,&b),v.push_back(make_pair(b,a));
sort(v.begin(),v.end());
priority_queue<int>q;
for(i=0;i<n;i++)if(s+=v[i].second,q.push(v[i].second),s>v[i].first)s-=q.top(),q.pop();
printf("%d\n",q.size());}