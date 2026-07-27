#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <ctime>
#include <unistd.h>
using namespace std;

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	unordered_map<int,unordered_map<int,int> >m;
	for(;M--;){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		m[a][b]=c;
	}
	uniform_int_distribution<int> distribution(0,N-1);
	mt19937_64 engine((unsigned int)time(NULL)^(getpid()<<16));
	vector<int>v(N),order(N);
	iota(order.begin(),order.end(),0);
	int r=0;
	for(int i=0;i<100000;i++){
		v=order;
		//random_shuffle(v.begin(),v.end());
		int a,b;
		a=distribution(engine),b=distribution(engine);
		swap(v[a],v[b]);
		a=distribution(engine),b=distribution(engine);
		swap(v[a],v[b]);
		int s=0;
		for(int i=0;i<N-1;i++)for(int j=i+1;j<N;j++)s+=m[v[i]][v[j]];
		if(r<s)r=s,order=v;
	};
	printf("%d",r);
	for(int i=0;i<N;i++)printf(" %d",order[i]);
}