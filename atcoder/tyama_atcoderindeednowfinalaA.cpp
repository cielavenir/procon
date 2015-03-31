#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	for(int i=0;i<N/2;i++)v[i]+=v[N-i-1];
	sort(v.begin(),v.begin()+N/2);
	printf("%d\n",v[N/2-1]-v[0]);
}