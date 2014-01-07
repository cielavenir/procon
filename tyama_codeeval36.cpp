#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int cnt;
string s;
int get(int n){
	int r=0;
	for(int i=0;i<n;i++)r=r*2+s[cnt++]-'0';
	return r;
}
main(){
	int n,x;
	for(;getline(cin,s);){
		for(cnt=0;s[cnt]!='0'&&s[cnt]!='1';cnt++);
		for(;n=get(3);)for(;(x=get(n))!=(1<<n)-1;)putchar(s[(1<<n)-n-1+x]);
		puts("");
	}
}