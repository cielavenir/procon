#include <stdio.h>
#include <string.h>
#include <stdbool.h>
long long icbrt(long long n){
    if(n<0)return -icbrt(-n);
    if(n==0)return 0;
    if(n<8)return 1;
    long long x=0,y=n;
    for(;x!=y&&x+1!=y;)x=y,y=(n/y/y+y*2)/3;
    return x;
}
bool ispalindrome(const char* s){
	int l=strlen(s)-1;
	for(int i=0;i<l;i++,l--){
		if(s[i]!=s[l])return false;
	}
	return true;
}
char buf[99];
int main(){
	long long n;
	scanf("%lld", &n);
	long long m=icbrt(n),r=m;
	for(;m>1;m--){
		r=m*m*m;
		sprintf(buf, "%lld", r);
		if(ispalindrome(buf))break;
	}
	printf("%lld\n", r);
}
