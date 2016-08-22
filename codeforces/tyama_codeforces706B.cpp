#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N,M;
	scanf("%d",&N);
	vector<int>a(N);
	for(int i=0;i<N;i++)scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	for(scanf("%d",&M);M--;){
		int e;
		scanf("%d",&e);
		printf("%d\n",distance(a.begin(),upper_bound(a.begin(),a.end(),e)));
	}
}