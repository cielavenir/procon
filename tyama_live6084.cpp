#include <cstdio>
#include <algorithm>
long long a,b,c,t;int main(){for(;scanf("%lld%lld%lld",&a,&b,&c),c;printf("Case %lld: %lld\n",++t,c/b*a+std::min(a,c%b)));}