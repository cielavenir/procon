#include <stdio.h>
#include <stdlib.h>
//isatty
#if defined(WIN32) || (!defined(__GNUC__) && !defined(__clang__))
	#include <io.h>
#else
	#include <unistd.h>
#endif
 
//1〜nに含まれるcountの個数を求める
unsigned long long solve(unsigned long long n,int count,int base){
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
	int count=1;
	int base=10;
	if(isatty(fileno(stdin))){
		fprintf(stderr,"count%d [count=%d] [base=%d] [<count%d.txt]\n",count,count,base,count);
	}
 
	if(argc>2)base=strtol(argv[2],NULL,10);
	if(argc>1)count=strtol(argv[1],NULL,base);
 
	unsigned long long n;
	for(;;){
		if(isatty(fileno(stdin)))printf("input> ");
		if(scanf("%llu",&n)<0)return 0;
		printf("%llu\n",solve(n,count,base));
	}
}
 
/*
1から10までに含まれる7の個数は1、
1から100までに含まれる7の個数は20、
1から1000までに含まれる7の個数は300、
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
*/