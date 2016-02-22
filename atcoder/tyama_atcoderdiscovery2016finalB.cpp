#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N,X,r=0;
	scanf("%d%d",&N,&X);
	vector<pair<int,int>>A(N);
	set<int>ti;
	for(int i=0;i<N;i++)scanf("%d",&A[i].second),ti.insert(i+1);
	for(int i=0;i<N;i++)scanf("%d",&A[i].first);
	sort(A.begin(),A.end(),greater<pair<int,int>>());
	for(int i=0;i<N;i++){
		int v=A[i].first,t=A[i].second;
		auto it=ti.upper_bound(t);
		if(it==ti.begin())continue;
		ti.erase(--it);
		r++;
		X-=v;
		if(X<=0){printf("%d\n",r);return 0;}
	}
	puts("-1");
}