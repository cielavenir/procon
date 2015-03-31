#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
int A[999999], W[999999];
long long merge_and_count(int l, int r) { // range [l,r)
	if (l+1 >= r) return 0; // empty
	if (l+2 == r) { // [l,r) == [l,l+1] 要素2つだけ
		if (A[l] < A[l+1]) return 0; // 逆転はなし
		if (A[l] == A[l+1]) {puts("-1");exit(0);}
		std::swap(A[l], A[l+1]);
		return A[l]; // 逆転一つ
	}
	int m = (l+r)/2; // [l,r) == [l,m) + [m,r)
	long long cl = merge_and_count(l, m); // 左半分を再帰的に数える
	long long cr = merge_and_count(m, r); // 右半分を再帰的に数える
	long long c = 0; // 左と右を混ぜるときの逆転数
	int i=l, j=m; // iは[l,m)を動き, jは[m,r)を動いて、
	int k=l; // 小さいものから W[k] に書き込む
	while (i<m && j<r) { // A[i]とA[j]を比べながら進む
		if (A[i] == A[j]) {puts("-1");exit(0);}
		if (A[i] < A[j]) W[k++] = A[i++]; // 左半分の方が小さく逆転なし
		else {
			W[k++] = A[j++];
			c += (long long)(m-i)*A[j-1]; // 左半分の方が大きい、左半分で未処理の要素だけ飛び越える
		}
	}
	while (i<m) W[k++] = A[i++]; // 左半分が余った場合
	while (j<r) W[k++] = A[j++]; // 右半分が余った場合
	//assert(k == r);
	std::copy(W+l, W+r, A+l);
	return cl + cr + c;
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",A+i);
	printf("%lld\n",merge_and_count(0,N));
}