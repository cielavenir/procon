#include <stdio.h>
#include <stdlib.h>
//isatty
#if defined(WIN32) || (!defined(__GNUC__) && !defined(__clang__))
	#include <io.h>
#else
	#include <unistd.h>
#endif

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

	if(argc>2)base=strtol(argv[2],NULL,10);
	if(argc>1)starting=strtoll(argv[1],NULL,base);

	long long n;
	for(;;){
		if(isatty(fileno(stdin)))printf("input> ");
		if(scanf("%lld",&n)<0)return 0;
		printf("%d\n",solve(n,starting,base));
	}
	return 0;
}
