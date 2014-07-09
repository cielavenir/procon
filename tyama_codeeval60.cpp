#include <set>
#include <queue>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int s(int n){
	int r=0;
	if(n<0)n=-n;
	for(;n;n/=10)r+=n%10;
	return r;
}
int main(){
	set<pii> h;
	h.insert(make_pair(0,0));
	queue<pii> q;
	q.push(make_pair(0,0));
	for(;!q.empty();){
		pii p=q.front();q.pop();
		for(int d=0;d<4;d++){
			pii next=make_pair(p.first+dx[d],p.second+dy[d]);
			if(h.find(next)==h.end() && s(p.first+dx[d])+s(p.second+dy[d])<20){
				h.insert(next);
				q.push(next);
			}
		}
	}
	printf("%d\n",h.size());
}