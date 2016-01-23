#include <stdio.h>
#include <stdlib.h>

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

int d[]={6,2,5,5,4,5,6,3,7,6};
int main(){
	int base=10;

	unsigned long long n,m,r=0;
	scanf("%lld%lld",&n,&m);
	int i=0;
	for(;i<10;i++)r+=d[i]*(solve(m,i,base)-solve(n-1,i,base));
	printf("%lld\n",r);
}