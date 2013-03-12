#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int n,x;
	set<int>s,t,r;
	for(scanf("%d",&n);n--;s.insert(x))scanf("%d",&x);
	for(scanf("%d",&n);n--;t.insert(x))scanf("%d",&x);
	set_intersection(s.begin(),s.end(),t.begin(),t.end(),inserter(r,r.end()));
	printf("%d\n",r.size());
}