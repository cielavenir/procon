#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

int S[100],R[100];
main(){
	int N,i=0,a,b,c,d;
	vector<pair<int,int> >v;
	scanf("%d",&N);
	for(;i<N*(N-1)/2;i++){scanf("%d%d%d%d",&a,&b,&c,&d);if(c==d)c=d=1;else if(c>d)c=3,d=0;else c=0,d=3;S[a-1]+=c,S[b-1]+=d;}
	for(i=0;i<N;i++)v.push_back(make_pair(S[i],i));
	sort(v.begin(),v.end(),greater<pair<int,int> >());
	for(R[v[0].second]=1,a=0,i=1;i<N;i++){if(v[i].first<v[a].first)a=i;R[v[i].second]=a+1;}
	for(i=0;i<N;i++)printf("%d\n",R[i]);
}