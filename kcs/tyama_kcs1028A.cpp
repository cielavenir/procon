#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	sort(v.begin(),v.end(),greater<int>());
	for(int i=0;i<N;i++)printf("%d\n",v[i]);
}