#!/usr/bin/rdmd
import std.cstream;

int main(){
	int n,k,m,r,i;
	for(;din.readf(&n,&k,&m),n;printf("%d\n",(r+m)%n+1))for(r=i=0;++i<n;r%=i)r+=k;
	return 0;
}