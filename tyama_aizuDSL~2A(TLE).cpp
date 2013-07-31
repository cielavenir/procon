#include <algorithm>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

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

int a[100000],*p;
int main(){
	int n,q,c,x,y,f=0;
	scanf("%d%d",&n,&q);
	for(y=0;y<n;y++)a[y]=0x7fffffff;
	for(;q--;){
		scanf("%d%d%d",&c,&x,&y);
		if(c){
			if(!f)p=buildRMQ(a,n),f=1;
			printf("%d\n",minimum(x,y,p,n));
		}else{
			if(f)delete []p,f=0;
			a[x]=y;
		}
	}
}