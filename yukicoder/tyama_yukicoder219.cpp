/*
累乗数の概算を見たいと思います。
A**B ≒ X.Y * 10**Z (A,B,X,Y,Zは整数、Xは1以上9以下、Yは0以上9以下、なおYより下位は切り捨てとする)
A,Bが複数与えられるので、あてはまるX,Y,Zを求めて下さい。なおZは0になることはないとします(0だと右辺が整数にならないので)。

log10(A)*Bの整数部分がスケールになります。
最上位の数を求めるにはlog10(1)〜log10(10)による挟み込みを用いることは高校で習うと思います。
今回は2桁必要です。
プログラムを書けば対数表が得られるので、予め作っておいた表を検索すればよいでしょう。
*/

// a=44**500;puts [a.to_s[0],a.to_s[1],a.to_s.size-1]*' '

#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	vector<long double>t(101);
	for(int i=10;i<101;i++)t[i]=log10l(i);
	int N;
	for(scanf("%d",&N);N--;){
		long long A,B;
		scanf("%lld%lld",&A,&B);
		long double result=log10l(A)*B;
		long long Z=result;
		result-=Z-1;
		auto it=upper_bound(t.begin(),t.end(),result);--it;
		int X=distance(t.begin(),it);
		printf("%d %d %lld\n",X/10,X%10,Z);
	}
}