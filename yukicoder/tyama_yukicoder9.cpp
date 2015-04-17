#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;
int perform(vector<int>&a,vector<int>&b){
	priority_queue<pii,vector<pii>,greater<pii> >q;
	for(auto &e:a)q.push({e,0});
	int ret=0;
	for(auto &e:b){
		pii cur=q.top();
		q.pop();
		cur.first+=e/2;
		ret=max(ret,++cur.second);
		q.push(cur);
	}
	return ret;
}

int main(){
	int N;
	scanf("%d",&N);
	vector<int>a(N);
	vector<int>b(N);
	for(int i=0;i<N;i++)scanf("%d",&a[i]);
	for(int i=0;i<N;i++)scanf("%d",&b[i]);
	int r=N;
	for(int i=0;i<N;i++){
		rotate(b.begin(),b.begin()+1,b.end());
		r=min(r,perform(a,b));
	}
	printf("%d\n",r);
}