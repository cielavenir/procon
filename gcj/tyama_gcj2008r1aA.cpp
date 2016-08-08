#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

int main(){
	int t=1,T,N;
	for(scanf("%d",&T);t<=T;t++){
		int N;
		long long R=0;
		scanf("%d",&N);
		vector<int>a(N);
		for(int i=0;i<N;i++)scanf("%d",&a[i]);
		vector<int>b(N);
		for(int i=0;i<N;i++)scanf("%d",&b[i]);
		sort(a.begin(),a.end());
		sort(b.begin(),b.end(),greater<int>());
		for(int i=0;i<N;i++)R+=(long long)a[i]*b[i];
		printf("Case #%d: %lld\n",t,R);
	}
}