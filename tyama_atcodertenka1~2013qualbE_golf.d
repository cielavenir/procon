#!/usr/bin/rdmd
import std.cstream;

int main(){
	int i;
	dout.writefln("100\n1 0");
	for(i=99;i>1;i--)dout.writefln("%d 0",i);
	dout.writefln("0 0");
	return 0;
}