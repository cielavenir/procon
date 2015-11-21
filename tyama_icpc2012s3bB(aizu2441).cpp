#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cf: http://www.ngc.is.ritsumei.ac.jp/~hossy/2015/06/aoj-2441-fizzbuzz/

char buf[999];
void solve(long long n){
	long long digits=2;
	long long expbase=1;
	long long s=1;
	long long x;
	for(;(x=(digits*8+32)*6*expbase-5)<=n;n-=x){
		digits++;
		expbase*=10;
		s=expbase*10-9;
	}
	if((x=(digits-1)*5+digits*3+32)<=n){
		n-=x;
		s+=15;
	}
	x=digits*8+32;
	s+=n/x*15;
	n-=n/x*x;
	int i=1;
	for(;i<=30;i++){
		if(i%15==0)sprintf(buf+strlen(buf),"FizzBuzz");
		else if(i%3==0)sprintf(buf+strlen(buf),"Fizz");
		else if(i%5==0)sprintf(buf+strlen(buf),"Buzz");
		else sprintf(buf+strlen(buf),"%lld",s+i-1);
	}
	buf[n+20]=0;
	puts(buf+n);
}
 
int main(int argc,char **argv){
	long long n;
	scanf("%lld",&n);
	solve(n-1);
	return 0;
}