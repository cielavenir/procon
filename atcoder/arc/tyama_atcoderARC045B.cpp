#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	vector<int>v(N+2);
	vector<pair<int,int> >q(M);
	for(int i=0;i<M;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x]++,v[y+1]--;
		q[i].first=x,q[i].second=y;
	}
	for(int i=1;i<N+2;i++)v[i]+=v[i-1];
	for(int i=1;i<N+2;i++)v[i]=v[i-1]+(v[i]==1);
	vector<int>result;
	for(int i=0;i<M;i++)if(v[q[i].second]-v[q[i].first-1]==0)result.push_back(i+1);
	printf("%d\n",result.size());
	for(int i=0;i<result.size();i++)printf("%d\n",result[i]);
}
