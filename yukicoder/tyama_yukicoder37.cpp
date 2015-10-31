#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int T,N,S=0;
	scanf("%d%d",&T,&N);
	vector<pair<int,int> >v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i].first);
	for(int i=0;i<N;i++)scanf("%d",&v[i].second);
	for(;N--;){
		int x=v[N].first,y=v[N].second;
		for(y/=2;y;y/=2)v.push_back(make_pair(x,y));
	}
	vector<int>bag(T+1);
	for(int i=0;i<v.size();i++)for(int j=T;j>=v[i].first;j--)bag[j]=max(bag[j],bag[j-v[i].first]+v[i].second);
	int r=0;
	for(int i=0;i<=T;i++)r=max(r,bag[i]);
	printf("%d\n",r);
}