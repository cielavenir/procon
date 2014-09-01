#include <queue>
#include <cstdio>
int main(){
	int n,k,i=0,x;
	scanf("%d%d",&n,&k);
	std::priority_queue<std::pair<int,int> >q;
	for(;i<n;i++){
		scanf("%d",&x);
		q.push(std::make_pair(x,i));
		if(q.size()>k)q.pop();
		if(q.size()==k)printf("%d\n",q.top().second+1);
	}
}