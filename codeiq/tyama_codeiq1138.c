/*
Code Teller [count7]
input: standard input
output: standard output
*/

#include <stdio.h>
#include <stdlib.h>

//1〜nに含まれるcountの個数を求める
unsigned long long solve(unsigned long long n,int count,int base){
	//なぜか？一部「0<A」を満たさない入力があるので、例外処理。
	//n==-1かつcount==0ならば-1を返す。すると+1になってうまいこと処理できる…。
	if(n==-1LL)return -(count==0);

	unsigned long long r=0; //結果
	unsigned long long lower=0; //処理している桁より下の桁の合計
	unsigned long long digits=0,expbase=1;
	for(;n;digits++,expbase*=base,n/=base){
		unsigned long long d=digits*expbase/base; //0,1,20,300,4000,...
		unsigned long long current_digit=n%base;
		r+=current_digit*d;
		if(current_digit==count)r+=lower+1;
		if(current_digit>=count+1)r+=expbase;
		lower+=current_digit*expbase;
		if(count==0)r-=expbase;
	}
	return r;
}

int main(int argc,char **argv){
	char id[9];
	int base=10,count;
	unsigned long long start,end,answer;
	for(;scanf("%s%llu,%llu,%d%llu",id,&start,&end,&count,&answer)>0;){
		unsigned long long ans=solve(end,count,base)-solve(start-1,count,base);
		if(ans!=answer){
			puts(id);
		}
	}
}

/*
【解答】
16,25,27,32,64,81,125,128,243,256,512,625,729
【感想・工夫した点など】
1から9までに含まれる7の個数は1、
1から99までに含まれる7の個数は20、
1から999までに含まれる7の個数は300、
以下同様に4000、50000、…、となる。
あとは、ある桁が7ならそれより下の桁+1(70〜79のように、先頭の0を含むから)を、8か9ならその切り上げを足し合わせれば良い。
例えば1912478368については次のように計算できる。
1 * 900000000
9 *  80000000 + 100000000
1 *   7000000
2 *    600000
4 *     50000
7 *      4000 +      8368+1
8 *       300 +      1000
3 *        20
6 *         1
8 *         0 +         1

0を数える場合は、1を桁数個並べた数を引けば良い。

[追記1]
n%baseを変数に受けました。
count_zero_flagのより良い変数名を思いつかなかったので、ループ中に減算処理を入れてしまいました。
最後に、(0を数える場合だけは処理を追加する必要がありましたが)コード銀行「7の数を数えよう」のほぼコピペで済ませたことをお詫びします。
ちなみに、コード銀行は全てC(++)で提出するようにしています。C++でできることは必ずRubyでもできるが逆は必ずしも真ならず(特にyield)。

>計算量との戦いがない
いや十分あるのでは。
https://codeiq.jp/wp/feedbacksample/ (解答例を見るとnthdigitは間違いでcount7だとわかるのですが)において、Aさんのコードは読みにくいという声が散見されますが、問題の趣旨を無視した発言であり、かなりいたたまれないです。
【言語と処理系】
C (C++互換)
gcc 4.2.1 (LLVM) or clang++ Apple LLVM 6.0 or g++-mp-4.8
【ソースコード】
*/