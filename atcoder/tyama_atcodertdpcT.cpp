#include <vector>
using namespace std;
#define reE(i,a,b) for(auto (i)=(a);(i)<=(b);(i)++)
#define rE(i,b) reE(i,0,b)
#define reT(i,a,b) for(auto (i)=(a);(i)<(b);(i)++)
#define rT(i,b) reT(i,0,b)
#define rep(i,a,b) reE(i,a,b);
#define rev(i,a,b) for(auto (i)=(b)-1;(i)>=(a);(i)--)
#define itr(i,b) for(auto (i)=(b).begin();(i)!=(b).end();++(i))
#define LL long long
#define all(b) (b).begin(),(b).end()

/*
http://nitcoder000.hatenablog.com/entry/kitamasa

使い方
M項間漸化式のN項目を計算する。Nの最小は1。
a[N]=sum(c[i]*a[N-M+i-1])の形。
Mrが本体、Xは使わなくてもできる問題はある。(MODを使わないint,LLなど)
Xは半環を満たすものならなんでもよい、+,*のオーバーロードにMODをねじこむ。
コンストラクタに初項、係数、M,*の単位元、+の単位元の順で引数を与える。
あとはcalcにNを与えるだけ。
*/
#define MAX_LOGN 32
template <class T>
struct Mr{
	vector<T> first;
	vector<T> C;
	vector<vector<T>> bin;
	T zero,one;
	int M;
	//n(1,,,2M)をn(1,,,M)に修正、O(M^2)
	void form(vector<T> &n){
		rev(i, M + 1, 2 * M + 1){
			reE(j, 1, M)n[i - j] = (n[i - j] + (C[M - j] * n[i]));
			n[i] = zero;
		}
	}
	//lとrを足し合わせる、O(M^2)
	void add(vector<T> &l, vector<T> &r, vector<T> &ans){
		reE(i, 1, 2 * M)ans[i] = zero;
		reE(i, 1, M)reE(j, 1, M)ans[i + j] = (ans[i + j] + (l[i] * r[j]));
		form(ans);
	}
	//初期化、O(M*MAX_LOGN)
	Mr(const vector<T>& f,const vector<T>& c,int m,T e1,T e0){
		M = m;
		first.reserve(M + 1);C.reserve(M);
		zero = e0, one = e1;
		first.push_back(zero); 
		rT(i, M){ first.push_back(f[i]); C.push_back(c[i]); }
		bin.resize(MAX_LOGN);
		rT(i, MAX_LOGN)bin[i].resize(2*M+1);
		rE(i, 2*M)bin[0][i] = zero; bin[0][1] = one;
		reT(i,1, MAX_LOGN){
			add(bin[i - 1], bin[i - 1], bin[i]);
		}
	}
	//N項目の計算、戻り値がTの形であることに注意、O(M^2*logN)
	T calc(LL n){
		n--;
		vector<T> tmp,result = bin[0];
		for (int b = 0; n; b++,n>>=1)
			if (1 & n){ tmp = result; add(tmp, bin[b], result); }
		T ans = zero;
		reE(i, 1, M)ans = ans + (result[i] * first[i]);
		return ans;
	}
};
//テンプレート、デフォルトコンストラクタのオーバーロードを忘れない
#define MOD 1000000007
struct X{
	LL val;
	X(LL  v){ val = v; }
	X(){ val = 0; }
	LL operator=(const X &another){ return val = another.val; }
	LL operator*(const X &another)const{ return (val*another.val)%MOD; }
	LL operator+(const X &another)const{ return (val+another.val)%MOD; }
};

#include <cstdio>
int main(){
	int K,N;
	scanf("%d%d",&K,&N);
	vector<X> A,B;
	A.reserve(K);
	B.reserve(K);
	rT(i, K){ A.push_back(X(1)); }
	rT(i, K){ B.push_back(X(1)); }
	Mr<X> mr(A,B,K,X(1),X(0));
	printf("%lld\n",mr.calc(N).val);
}