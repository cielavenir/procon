#include <queue>
#include <cstdio>
int main(){
	int N,M,x,r=0;
	scanf("%d%d",&N,&M);
	std::priority_queue<int>q;
	for(;N--;)scanf("%d",&x),q.push(-x);
	for(;M--;){
		x=q.top();
		q.pop();
		if(~x)q.push(x+1);
		else r++;
	}
	printf("%d\n",r);
}