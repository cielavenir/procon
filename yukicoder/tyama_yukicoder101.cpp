#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
using namespace std;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	vector<int>shuf(N);
	iota(shuf.begin(),shuf.end(),0);
	vector<int>orig=shuf;
	for(int i=0;i<K;i++){
		int a,b;
		scanf("%d%d",&a,&b),a--,b--;
		swap(shuf[a],shuf[b]);
	}
/*
	vector<int>v=shuf;
	int x=1;
	for(;v!=orig;x++){
		vector<int>nxt(N);
		for(int i=0;i<N;i++)nxt[i]=v[shuf[i]];
		v=nxt;
	}
	printf("%d\n",x);
*/
	vector<int>elem(N);
	for(int i=0;i<N;i++){
		int x=shuf[i],c=1;
		for(;x!=i;c++)x=shuf[x];
		elem[i]=c;
	}
	for(int i=elem.size()-1;i>0;i--){
		elem[i-1]=elem[i-1]/gcd(elem[i-1],elem[i])*elem[i];
	}
	printf("%d\n",elem[0]);
}