#include <queue>
#include <cstdio>
#define M 500000
using namespace std;
int main(){
	int n;
	long long k;
	scanf("%d",&n);
	std::vector<double>v(n);
	priority_queue<pair<double,int> >pq;
	for(int i=0;i<n;i++){
		scanf("%lf",&v[i]);
		pq.push(make_pair(v[i],1));
	}
	vector<double>K(M+1);
	for(int i=1;i<=M;i++){
		auto e=pq.top();pq.pop();
		K[i]=e.first;
		pq.push(make_pair(e.first*e.second/(e.second+1),e.second+1));
	}
	for(scanf("%d",&n);n--;)scanf("%lld",&k),printf("%.9f\n",K[k]);
}