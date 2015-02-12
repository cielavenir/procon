#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N,K,Q;
	scanf("%d%d",&N,&K);
	vector<int> C(N);
	for(int i=0;i<N;i++)scanf("%d",&C[i]);
	scanf("%d",&Q);
	if(Q)return 1;

	sort(C.begin(),C.end());
	vector<int> diff(N-1);
	for(int i=0;i<N-1;i++)diff[i]=C[i+1]-C[i];
	sort(diff.begin(),diff.end());
	int ret=0;
	for(int i=0;i<N-K;i++)ret+=diff[i];
	printf("%d\n",ret);
}