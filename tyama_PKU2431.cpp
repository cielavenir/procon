#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N,L,P;
	scanf("%d",&N);
	vector<pair<int,int> >a(N+1);
	for(int i=N-1;i>=0;i--)scanf("%d%d",&a[i].first,&a[i].second);
	scanf("%d%d",&L,&P);
	for(int i=0;i<N;i++)a[i].first=L-a[i].first;
	a[N].first=L;
	a[N].second=0;
	sort(a.begin(),a.end());
	priority_queue<int>q;

	int ans=0,pos=0,tank=P;
	for(int i=0;i<=N;i++){
		int d=a[i].first-pos;
		for(;tank-d<0;){
			if(q.empty()){
				puts("-1");
				return 0;
			}
			tank+=q.top();
			q.pop();
			ans++;
		}
		tank-=d;
		pos=a[i].first;
		q.push(a[i].second);
	}
	printf("%d\n",ans);
}