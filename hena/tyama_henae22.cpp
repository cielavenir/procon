//https://qiita.com/Nabetani/items/891d07f4d645ec00ce9a
//http://nabetani.sakura.ne.jp/hena/orde18twintri/
#pragma GCC optimize("O3")
#pragma GCC target("avx")

#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

void convert(vector<pair<vector<char>,int>>&v,int i,int m,int b){
	vector<char>v0;
	int n=i+m;
	for(;n;){
		v0.push_back(n%b);
		n/=b;
	}
	reverse(v0.begin(),v0.end());
	v[i].first=v0;
	v[i].second=i+m;
}

int main(){
	int m,n,b,x;
	for(;~scanf("%d,%d,%d,%d",&m,&n,&b,&x);){
		int siz=n-m+1,i;
		vector<pair<vector<char>,int>>v(siz);
#pragma omp parallel for
		for(i=0;i<siz;i++){
			convert(v,i,m,b);
		}
		sort(v.begin(),v.end());
		printf("%d\n",v[x-1].second);
		fflush(stdout);
	}
}
