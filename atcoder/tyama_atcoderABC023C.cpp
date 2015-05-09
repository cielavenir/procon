#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int R,C,K,N;
	scanf("%d%d%d%d",&R,&C,&K,&N);
	vector<int>vr(R),vc(C);
	vector<pair<int,int> >candy(N);
	for(int i=0;i<N;i++){
		int r,c;
		scanf("%d%d",&r,&c),r--,c--;
		vr[r]++,vc[c]++;
		candy[i]={r,c};
	}
	long long r=0;
	map<int,int>mr,mc;
	for(auto &e:vr)mr[e]++;
	for(auto &e:vc)mc[e]++;
	for(auto &e:mr)r+=(long long)e.second*mc[K-e.first];
	for(auto &e:candy){
		r-=vr[e.first]+vc[e.second]==K;
		r+=vr[e.first]+vc[e.second]==K+1;
	}
	printf("%lld\n",r);
}