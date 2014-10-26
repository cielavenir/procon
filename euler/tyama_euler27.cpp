#include <algorithm>
#include <tuple>
#include <cstdio>
#define M 10000000
using namespace std;

int t[M+1];
int len(int a,int b){
	int n=0;
	for(;n*n+a*n+b>=2&&!t[n*n+a*n+b];n++);
	return n;
}
int main(){
	int n,a,b;
	for(a=2;a<=M;a++)if(!t[a])for(b=a*2;b<=M;b+=a)t[b]=1;
	scanf("%d",&n);
	tuple<int,int,int>r=make_tuple(-1,0,0);
	for(a=-n;a<=n;a++)
		for(b=-n;b<=n;b++)
			r=max(r,make_tuple(len(a,b),a,b));
	printf("%d %d\n",get<1>(r),get<2>(r));
}
// 999