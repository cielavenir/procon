#include <queue>
#include <cstdio>
using namespace std;

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	priority_queue<int>q;
	for(int i=0,x;i<N;i++)scanf("%d",&x),q.push(-x);
	for(int n=0;;n++){
		int a=q.top();
		if(-a>=K){
			printf("%d\n",n);
			break;
		}
		q.pop();
		if(q.empty()){
			puts("-1");
			break;
		}
		int b=q.top();
		q.pop();
		q.push(a+b*2);
	}
}