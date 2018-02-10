#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
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
  int z = y - x, k = 0, e = 1, s; // max k where y - x >= e = 2^k
  s = ( (z & 0xffff0000) != 0 ) << 4; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x0000ff00) != 0 ) << 3; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x000000f0) != 0 ) << 2; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x0000000c) != 0 ) << 1; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x00000002) != 0 ) << 0; z >>= s; e <<= s; k |= s;
  return min( rmq[x+n*k], rmq[y+n*k-e+1] );
}

int calc(const string &s,const string &t){
	int l=min(s.size(),t.size()),i=0;
	for(;i<l&&s[i]==t[i];i++);
	return i;
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,I,J,M;
	long long X,D,R=0;
	cin>>N;
	vector<string>v(N);
	vector<int>tbl(N),rev(N);
	for(int i=0;i<N;i++)cin>>v[i],tbl[i]=i;
	cin>>M>>X>>D;
	sort(tbl.begin(),tbl.end(),[&](int i,int j)->bool{
		return v[i]<v[j];
	});
	for(int i=0;i<N;i++)rev[tbl[i]]=i;
	int rmq0[N];rmq0[0]=0;
	for(int i=0;i<N-1;i++)rmq0[i+1]=calc(v[tbl[i]],v[tbl[i+1]]);
	int *rmq=buildRMQ(rmq0,N);
	for(;M--;){
		I=X/~-N,J=X%~-N,X=(X+D)%((long long)N*~-N);
		if(I>J)swap(I,J);else ++J;
		int i=rev[I],j=rev[J];
		if(i>j)swap(i,j);
		R+=minimum(i+1,j,rmq,N);
	}
	delete[] rmq;
	cout<<R<<endl;
}
