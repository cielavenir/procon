//https://qiita.com/Nabetani/items/99e38a39165e1905b415
//http://nabetani.sakura.ne.jp/hena/orde22numord/
#pragma GCC optimize("O3")
#pragma GCC target("avx")

#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#if _OPENMP
#include <parallel/algorithm>
#endif

void convert(vector<pair<long long,int>>&v,int i,int m,int b,long long k){
	int n=i+m;
	for(;n;n/=b)k/=b;
	v[i].first=(i+m)*k;
	v[i].second=i+m;
}

int main(){
	int m,n,b,x;
	for(;~scanf("%d,%d,%d,%d",&m,&n,&b,&x);){
		int siz=n-m+1,i;
		long long k=1;
		for(;k<=n;k*=b);
		vector<pair<long long,int>>v(siz);
#pragma omp parallel for
		for(i=0;i<siz;i++){
			convert(v,i,m,b,k);
		}
#if _OPENMP
		__gnu_parallel::sort(
#else
		sort(
#endif
			v.begin(),v.end()
		);
		printf("%d\n",v[x-1].second);
		fflush(stdout);
	}
}
