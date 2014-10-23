//22GB memory required. Had to use super-computer.

#include <algorithm>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

#define N 100000000
#define K 100000

long long *buildRMQ(long long *a, long long n) {
  long long logn = 1;
  for (long long k = 1; k < n; k *= 2) ++logn;
  long long *r = new long long[n * logn];
  long long *b = r; copy(a, a+n, b);
  for (long long k = 1; k < n; k *= 2) {
    copy(b, b+n, b+n); b += n;
    REP(i, n-k) b[i] = max(b[i], b[i+k]);
  }
  return r;
}
long long maximum(long long x, long long y, long long *rmq, long long n) {
  long long z = y - x, k = 0, e = 1, s; // max k where y - x >= e = 2^k
  s = ( (z & 0xffff0000) != 0 ) << 4; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x0000ff00) != 0 ) << 3; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x000000f0) != 0 ) << 2; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x0000000c) != 0 ) << 1; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x00000002) != 0 ) << 0; z >>= s; e <<= s; k |= s;
  return max( rmq[x+n*k], rmq[y+n*k-e+1] );
}

long long a[N+1];
int main(){
	long long i,j,k;
	long long *b=new long long[N+1];
	for(i=0;i<=N;i++)a[i]=1,b[i]=i;
	for(i=2;i<=N;i++)if(a[i]==1)for(j=i;j<=N;j+=i){
		for(k=1;b[j]%i==0;k++)b[j]/=i;
		a[j]*=k;
	}
	delete []b;
	puts("divisornum ok");
	long long *rmq=buildRMQ(a,N+1);
	puts("rmq ok");
	long long r=0;
	for(i=1;i<=N-K+1;i++){
		r+=maximum(i,i+K-1,rmq,N+1);
	}
	puts("summation ok");
	delete []rmq;
	printf("%lld\n",r);
	return 0;
}