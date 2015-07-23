#!/usr/bin/rdmd
import std.stdio;

int main(){
	int a,b;
	string s;
	readf("%d %d\n%s\n",&a,&b,&s);
	writefln("%d %s",a+b,s);
	return 0;
}