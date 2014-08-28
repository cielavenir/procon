#include <stdio.h>

int solve(long long n,long long starting,int base){
	n+=starting-2;
	long long digits=1;
	long long expbase=1;
	long long x;
	for(;(x=digits*expbase*(base-1))<=n;n-=x){
		digits++;
		expbase*=base;
	}
	//(digits)桁の数を並べた中のn桁目を求めれば良い
	long long num=expbase+n/digits;
	long long d=digits-1-n%digits;
	for(;d--;num/=base);
	return num%base;
}

int main(int argc,char **argv){
	long long starting=1;
	int base=10;

	int T,r,i;
	for(scanf("%d",&T);T--;){
		long long l;
		r=1;
		for(i=0;i<7;i++)scanf("%lld",&l),r*=solve(l,starting,base);
		printf("%d\n",r);
	}
}
// 1 1 10 100 1000 10000 100000 1000000