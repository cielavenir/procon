#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;
//http://abc020.contest.atcoder.jp/submissions/365342
int main(){
	int N,K;
	vector<int>d;
	scanf("%d%d",&N,&K);
	for(int i=1;i*i<=K;i++)if(K%i==0){
		d.push_back(i);
		if(i*i!=K)d.push_back(K/i);
	}
	sort(d.begin(),d.end(),greater<int>());
	long long M=1000000007,R=0;
	vector<long long>s(d.size());
	for(int i=0;i<d.size();i++){
		long long n=d[i];
		s[i]=(n+(N-N%n))*(N/n)/2%M;
		for(int j=0;j<i;j++)if(d[j]%d[i]==0)s[i]-=s[j];
		R+=(s[i]%M+M)%M*K/n;
	}
	printf("%lld\n",R%M);
}