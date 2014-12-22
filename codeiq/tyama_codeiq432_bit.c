// http://antimon2.hatenablog.jp/entry/2013/09/02/190039
// 0.06sec on MBA Core i7. bah!
#include <stdio.h>
int A[999999],W[999999];
long long bit(int n){
	long long ret=0;
	int i=n-1,idx;
	for(;i>=0;i--){
		for(idx=A[i];idx;idx&=idx-1)ret+=W[idx];
		for(idx=A[i];idx<n;idx+=idx&-idx)W[idx]++;
	}
	return ret;
}
int main(){
	int T,i,N;
	for(N=0;~scanf("%d",A+N);N++);printf("%lld\n",bit(N));
	return 0;
}