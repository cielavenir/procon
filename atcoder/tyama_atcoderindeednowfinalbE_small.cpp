#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int N;
	long long r=0;
	scanf("%d",&N);
	vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	for(int i=0;i<N-1;i++){
		for(int j=0;j<N-i-1;j++){
			if(v[j]>v[j+1])r+=v[j+1],swap(v[j],v[j+1]);
			if(v[j]==v[j+1]){puts("-1");return 0;}
		}
	}
	printf("%lld\n",r);
}