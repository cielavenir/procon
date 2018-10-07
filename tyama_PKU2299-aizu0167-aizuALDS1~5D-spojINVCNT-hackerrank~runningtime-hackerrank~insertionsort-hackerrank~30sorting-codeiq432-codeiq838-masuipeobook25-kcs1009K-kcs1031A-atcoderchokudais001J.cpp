#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
int A[999999], W[999999];
long long merge_and_count(int l, int r) { // range [l,r)
	if (l+1 >= r) return 0; // empty
	if (l+2 == r) { // [l,r) == [l,l+1] 要素2つだけ
		if (A[l] <= A[l+1]) return 0; // 逆転はなし
		std::swap(A[l], A[l+1]);
		return 1; // 逆転一つ
	}
	int m = (l+r)/2; // [l,r) == [l,m) + [m,r)
	long long cl = merge_and_count(l, m); // 左半分を再帰的に数える
	long long cr = merge_and_count(m, r); // 右半分を再帰的に数える
	long long c = 0; // 左と右を混ぜるときの逆転数
	int i=l, j=m; // iは[l,m)を動き, jは[m,r)を動いて、
	int k=l; // 小さいものから W[k] に書き込む
	while (i<m && j<r) { // A[i]とA[j]を比べながら進む
		if (A[i] <= A[j]) W[k++] = A[i++]; // 左半分の方が小さく逆転なし
		else {
			W[k++] = A[j++];
			c += m-i; // 左半分の方が大きい、左半分で未処理の要素だけ飛び越える
		}
	}
	while (i<m) W[k++] = A[i++]; // 左半分が余った場合
	while (j<r) W[k++] = A[j++]; // 右半分が余った場合
	//assert(k == r);
	std::copy(W+l, W+r, A+l);
	return cl + cr + c;
}
int main(){
	int T,i,N;
	//PKU2299,aizu0167: バブルソートの交換回数
	//for(;scanf("%d",&N),N;printf("%lld\n",merge_and_count(0,N)))for(i=0;i<N;i++)scanf("%d",A+i);
	//hackerrank~runningtime,aizuALDS1~5D,chokudais001J,yukicoder742
	scanf("%d",&N);for(i=0;i<N;i++)scanf("%d",A+i);printf("%lld\n",merge_and_count(0,N));
	//hackerrank~30-sorting
	//scanf("%d",&N);for(i=0;i<N;i++)scanf("%d",A+i);printf("Array is sorted in %lld swaps.\n",M(0,N)),printf("First Element: %d\nLast Element: %d\n",A[0],A[N-1]);
	//spojINVCNT,hackerrank~insertionsort
	//for(scanf("%d",&T);T--;printf("%lld\n",merge_and_count(0,N)))for(scanf("%d",&N),i=0;i<N;++i)scanf("%d",A+i);
	//codeiq432: 光線の交差数
	//for(N=0;~scanf("%d",A+N);N++);printf("%lld\n",merge_and_count(0,N));
	//codeiq838: あみだくじの最小本数
	//T=0,N=7;
	//std::vector<int>v(N);
	//std::iota(v.begin(),v.end(),1);
	//do{std::copy(v.begin(),v.end(),A);if(merge_and_count(0,N)==10)T++;}while(std::next_permutation(v.begin(),v.end()));
	//printf("%d\n",T); //573
	//kcs1009K: Nパズルの可解性
	//for(i=0;~(N=getchar());)if('0'<N&&N<'9')A[i++]=N-'0';
	//puts(merge_and_count(0,i)%2?"lmpossible":"Possible"); //"l"? lol!
	//atcoderutpc2014F: パリティ
	//for(scanf("%d",&T),getchar();T--;printf("%lld\n",merge_and_count(0,N)%2))for(N=0;~(A[N]=getchar())&&A[N]!='\n';N++);
	//kcs1031A
	//scanf("%d%d",&N,&T);for(i=0;i<N;i++)scanf("%d",A+i);printf("%lld\n",std::max(merge_and_count(0,N)-T,0LL));
	//masuipeobook25: オシャレな靴ひもの結び方
	//{0,5,4,5,3,4,2,3,1,2,0,1}のinversion countを取れば良い
#if 0
	T=0,N=12;
	std::vector<int>v(N);
	for(i=0;i<N/2;i++)v[2*i]=v[2*i+1]=i;
	rotate(v.begin(),v.begin()+1,v.end());
	do{
		std::swap(v[N-2],v[N-1]);
		for(i=0;i<N/2;i++){
			if(v[2*i]>=v[2*i+1])break;//同じ穴に結線しているか、inversion countを行える条件を満たさない
		}
		if(i==N/2){
			std::copy(v.begin(),v.end(),A),T=std::max((long long)T,merge_and_count(0,N));
			if(T==45)std::cout<<v<<std::endl;
		}
		std::swap(v[N-2],v[N-1]);
	}while(std::next_permutation(v.begin()+1,v.end()-1));
	printf("%d\n",T);
#endif
	//atcoderARC075E: 算術平均がT以上
	//A,Wをlong longにする必要あり
	//scanf("%d%d",&N,&T);for(i=1;i<=N;i++)scanf("%d",&A[i]);for(i=1;i<=N;i++)A[i]+=A[i-1]-T;printf("%lld\n",(long long)N*-~N/2-merge_and_count(0,N+1));
	//atcoderARC101D
#if 0
	scanf("%d",&N);std::vector<int>v(N);for(T=i=0;i<N;i++){scanf("%d",&v[i]);if(v[i]>T)T=v[i];}
	//実際には探索範囲はvの要素に限定できる
	printf("%d\n",binarysearch(1,T,1,[&](int m){
		A[0]=0;
		for(i=1;i<=N;i++)A[i]=A[i-1]+(v[i-1]>m?1:-1);
		long long r=merge_and_count(0,N+1);
		return r>=(long long)(N+1)*N/4+1;
	}));
#endif
}

/*
24689222839,0
ENV: C++

以前15パズルの可解性について調べていた時に「転倒数/転位数」という言葉を知った。
この問題の「交差数」とは、この転倒数に他ならない。
そして転倒数は分割統治法を用いることでO(nlogn)で求めることができる。
ハマりどころとしては、long longを用いなければオーバーフローを起こしてしまうところだろうか。

timeコマンドの出力によるreal(実時間)が常に0.1s未満であったので速度は十分とした。
なお、ナイーブ解法(O(n^2))だとg++ -O3でも44秒要してしまった。
---
#include <cstdio>
#include <vector>
using namespace std;
int main(){
	int n,i;
	long long r=0;
	vector<int>v;
	for(;~scanf("%d",&n);){
		for(i=0;i<v.size();i++)if(v[i]>n)r++;
		v.push_back(n);
	}
	printf("%lld\n",r);
}
---

ロジックのテストは http://poj.org/problem?id=2299 で行なっている。
*/
