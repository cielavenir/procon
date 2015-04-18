#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int perform(vector<int>&a,vector<int>&b,long long K){
	int r=0,d=a.size();
	//for(auto &e:a)r+=distance(b.begin(),upper_bound(b.begin(),b.end(),K/e));
	for(auto &e:a){for(;d&&b[d-1]>K/e;d--);r+=d;}
	return r;
}

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	vector<int>a(N),b(N);
	for(int i=0;i<N;i++)scanf("%d",&a[i]);
	for(int i=0;i<N;i++)scanf("%d",&b[i]);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	long long lo=1,hi=1LL<<61;
	for(;lo<hi;){
		long long mi=(lo+hi)/2;
		if(perform(a,b,mi)<K){
			lo=mi+1;
		}else{
			hi=mi;
		}
	}
	printf("%lld\n",lo);
}