#include <vector>
#include <algorithm>
#include <cstdio>
#define abs(a) ((a)<0?-(a):(a))
using namespace std;
typedef pair<long long,int> pli;

int main(){
	int N,M,i,y;
	long long x,a,p,r=0;
	scanf("%d%d%lld%lld%lld",&N,&M,&x,&a,&p);
	vector<pli>v(N*M);
	v[0]=make_pair(x,0);
	for(i=1;i<N*M;i++)v[i]=make_pair((v[i-1].first+a)%p,i);
	sort(v.begin(),v.end());
	for(y=0;y<N;y++){
		vector<pli>w(M);
		for(i=0;i<M;i++)w[i]=v[y*M+i];
		sort(w.begin(),w.end(),[&](const pli &a,const pli &b){return a.second%M<b.second%M;});
		for(i=0;i<M;i++){
			int a=w[i].second%M,b=w[i].second/M,c=i,d=y;
			r+=abs(a-c)+abs(b-d);
		}
	}
	printf("%lld\n",r);
}