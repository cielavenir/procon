#include <vector>
#include <algorithm>
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
	const int M=200001;
	fenwick_tree<int> bit(M);
	int Q,T,X;
	for(scanf("%d",&Q);Q--;){
		scanf("%d%d",&T,&X);
		if(T==1){
			bit.add(X,1);
		}else{
			int l=0,r=M;
			for(;l<r;){
				int m=(l+r)/2;
				int c=bit.sum(0,m);
				if(c<X){
					l=m+1;
				}else{
					r=m;
				}
			}
			printf("%d\n",r);
			bit.add(l,-1);
		}
	}
}