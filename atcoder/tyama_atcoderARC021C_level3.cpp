#include <queue>
#include <cstdio>
using namespace std;
typedef pair<long long,long long> pll;
int main(){
	int k,n;
	long long a,d,r=0;
	priority_queue<pll,vector<pll>,greater<pll> > q;
	scanf("%d%d",&k,&n);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&a,&d);
		q.push(make_pair(a,d));
	}
	for(int i=0;i<k;i++){
		pll p=q.top();
		q.pop();
		r+=p.first;
		q.push(make_pair(p.first+p.second,p.second));
	}
	printf("%lld\n",r);
}