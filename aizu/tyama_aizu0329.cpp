#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	map<long long,int>m={{0,-1}};
	long long s=0,x;
	int N,r=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%lld",&x);
		s+=x;
		if(m.find(s)==m.end())m[s]=i;
		r=max(r,i-m[s]);
	}
	printf("%d\n",r);
}
