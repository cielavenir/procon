#include <map>
#include <set>
#include <queue>
#include <cstdio>
using namespace std;

int main(){
	int N;
	map<int,set<int> >g;
	scanf("%d",&N);
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].insert(b);
		g[b].insert(a);
	}
	set<int>s={1};
	priority_queue<int,vector<int>,greater<int> >q;
	printf("1");
	for(q.push(1);!q.empty();){
		int cur=q.top();q.pop();
		if(cur!=1)printf(" %d",cur);
		for(auto &e:g[cur]){
			if(s.find(e)==s.end()){
				s.insert(e);
				q.push(e);
			}
		}
	}
	puts("");
}