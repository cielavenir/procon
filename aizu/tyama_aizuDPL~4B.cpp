#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int N,K;
	long long L,R;
	scanf("%d%d%lld%lld",&N,&K,&L,&R);
	int n=N/2;
	vector<long long>v(N);
	for(int i=0;i<N;i++)scanf("%lld",&v[i]);
	multiset<pair<int,long long>>se1;
	vector<pair<int,long long>>se2;
	for(int i=0;i<1<<n;i++){
		int m=0;
		long long V=0;
		for(int j=0;j<n;j++)if(i&(1<<j))m++,V+=v[j];
		se1.emplace(m,V);
	}
	for(int i=0;i<1<<(N-n);i++){
		int m=0;
		long long V=0;
		for(int j=0;j<(N-n);j++)if(i&(1<<j))m++,V+=v[j+n];
		se2.emplace_back(m,V);
	}
	sort(se2.begin(),se2.end());
	long long r=0;
	for(auto &e1:se1){
		//枚数=K-e1.first
		//合計=L-e1.second以上R-e1.second以下
		auto it1=lower_bound(se2.begin(),se2.end(),make_pair(K-e1.first,L-e1.second));
		auto it2=upper_bound(se2.begin(),se2.end(),make_pair(K-e1.first,R-e1.second));
		r+=distance(it1,it2);
	}
	printf("%lld\n",r);
}
