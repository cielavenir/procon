#include <algorithm>
#include <cstdio>
#define REP(i,n) for(int i=0;i<(int)n;++i)
using namespace std;
int *buildRMQ(int *a, int n) {
  int logn = 1;
  for (int k = 1; k < n; k *= 2) ++logn;
  int *r = new int[n * logn];
  int *b = r; copy(a, a+n, b);
  for (int k = 1; k < n; k *= 2) {
    copy(b, b+n, b+n); b += n;
    REP(i, n-k) b[i] = min(b[i], b[i+k]);
  }
  return r;
}
int minimum(int x, int y, int *rmq, int n) {
  int z = y - x, k = 0, e = 1, s; // y - x >= e = 2^k なる最大 k
  s = ( (z & 0xffff0000) != 0 ) << 4; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x0000ff00) != 0 ) << 3; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x000000f0) != 0 ) << 2; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x0000000c) != 0 ) << 1; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x00000002) != 0 ) << 0; z >>= s; e <<= s; k |= s;
  return min( rmq[x+n*k], rmq[y+n*k-e+1] );
}

int a[100000],*r;
int main(){
	int n,t,i,j;
	for(i=0,scanf("%d%d",&n,&t);i<n;i++)scanf("%d\n",a+i);
	r=buildRMQ(a,n);
	for(;t--;){
		scanf("%d%d",&i,&j);
		printf("%d\n",minimum(i,j,r,n));
	}
}