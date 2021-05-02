#include <set>
#include <random>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <unistd.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
	int N,M,K,total=0,ok=0;
	scanf("%d%d%d",&N,&M,&K);
	uniform_int_distribution<int> distribution(0,N-1);
	mt19937_64 engine((unsigned int)time(NULL)^(getpid()<<16));

	set<pii>se;
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		se.insert({a,b});
	}
	for(int T=700000;T--;){
		vector<int>v(N);
		iota(v.begin(),v.end(),0);
		for(int i=0;i<K;i++){
			int a=0,b=0;
			for(;a==b;)a=distribution(engine),b=distribution(engine);
			swap(v[a],v[b]);
		}
		int i=0;
		for(;i<N;i++){
			pii p={min(v[i],v[(i+1)%N]),max(v[i],v[(i+1)%N])};
			if(se.find(p)!=se.end())break;
		}
		total++;
		ok+=i==N;
	}
	printf("%f\n",ok*1.0/total);
}