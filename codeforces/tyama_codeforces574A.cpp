#include <queue>
#include <cstdio>
using namespace std;
int main(){
	int N,X,R=0,t;
	scanf("%d%d",&N,&X);
	vector<int>v(N);
	priority_queue<int>q;
	for(int i=1;i<N;i++)scanf("%d",&t),q.push(t);
	for(;;R++){
		t=q.top();q.pop();
		if(t<X+R)break;
		q.push(t-1);
	}
	printf("%d\n",R);
}