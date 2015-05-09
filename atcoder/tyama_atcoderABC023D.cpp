#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

bool chk(long long x,vector<pair<long long,long long> >&balloon){
	vector<long long>z(balloon.size());
	for(int i=0;i<balloon.size();i++){
		if(x-balloon[i].first<0)return false;
		z[i]=(x-balloon[i].first)/balloon[i].second;
	}
	sort(z.begin(),z.end());
	for(int i=0;i<z.size();i++)if(z[i]<i)return false;
	return true;
}

int main(){
	int N;
	scanf("%d",&N);
	vector<pair<long long,long long> >balloon(N);
	long long lo=0,hi=0;
	for(int i=0;i<N;i++){
		long long h,s;
		scanf("%lld%lld",&h,&s);
		balloon[i]=make_pair(h,s);
		hi=max(hi,h+s*N);
	}
	for(;lo<hi;){
		long long mi=(lo+hi)/2;
		if(chk(mi,balloon))hi=mi;
		else lo=mi+1;
	}
	printf("%lld\n",lo);
}