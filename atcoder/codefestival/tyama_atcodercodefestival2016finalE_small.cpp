#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <cstdio>
using namespace std;
 
int main(){
	long long N,A,R;
	scanf("%lld%lld",&N,&A);R=N;
	if(N>1000000)return 1;
 
	map<pair<long long,long long>,long long>m; //m<n,speed>=time
	m[{0,1}]=0;
	queue<pair<pair<long long,long long>,long long> >q;
	q.push({{0,1},0});
	for(;!q.empty();){
		auto cur=q.front();q.pop();
		long long n=cur.first.first;
		long long speed=cur.first.second;
		long long time=cur.second;
		if(time>=R)continue;
 
		vector<pair<pair<long,long>,long long> >nxt={
			{{0,n},time+A},
			{{n+speed,speed},time+1}
		};
		for(auto &e:nxt){
			long long nxtn=e.first.first;
			long long nxtspeed=e.first.second;
			long long nxttime=e.second;
			if(nxtn>=N){
				R=min(R,nxttime);
			}else if(nxttime<R && (m.find(e.first)==m.end()||m[e.first]>nxttime)){
				m[e.first]=e.second;
				q.push(e);
			}
		}
	}
	printf("%lld\n",R);
}
