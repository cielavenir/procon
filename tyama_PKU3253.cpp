#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	long long r=0;
	int N,x;
	scanf("%d",&N);
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=0;i<N;i++)scanf("%d",&x),q.push(x);
	for(int i=0;i<N-1;i++){
		x=q.top();
		q.pop();
		x+=q.top();
		q.pop();
		r+=x;
		q.push(x);
	}
	printf("%lld\n",r);
}