#include <vector>
#include <cstdio>
using namespace std;

template <class T>
struct fenwick_tree {
  vector<T> x;
  fenwick_tree(int n) : x(n, 0) { }
  T sum(int i, int j) {
    if (i == 0) {
      T S = 0;
      for (; j >= 0; j = (j & (j + 1)) - 1) S += x[j];
      return S;
    } else return sum(0, j) - sum(0, i-1);
  }
  void add(int k, T a) {
    for (; k < x.size(); k |= k+1) x[k] += a;
  }
};

int main(){
	int n,q,c,x,y;
	scanf("%d%d",&n,&q);
	fenwick_tree<long long> f(n);
	for(x=0;x<n;x++)scanf("%d",&y),f.add(x,y);
	for(;q--;){
		scanf("%d%d%d",&c,&x,&y);
		if(c==1)printf("%lld\n",f.sum(x-1,y-1));
		else f.add(x-1,y);
	}
}