#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N,P,Q;
	scanf("%d%d%d",&N,&P,&Q);
	vector<long long>c(N),a(N+1);
	for(int i=0;i<N;i++){
		scanf("%lld",&c[i]);
		c[i]+=(long long)P*i;
		a[i+1]=(long long)P*(Q+i*2)+a[i];
	}
	sort(c.begin(),c.end());
	long long s=0,ma=a[N];
	for(int i=N-1;i>=0;i--){
		s+=c[i];
		ma=max(ma,s+a[i]);
	}
	printf("%lld\n",ma-(long long)P*N*(N-1)/2);
}