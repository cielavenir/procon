#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cstdio>
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
	vector<int>v(N);
	iota(v.begin(),v.end(),0);
	int r=0;
	do{
		int s=0;
		for(int i=0;i<N-1;i++)for(int j=i+1;j<N;j++)s+=m[v[i]][v[j]];
		if(r<s)r=s;
	}while(next_permutation(v.begin(),v.end()));
	printf("%d\n",r);
}