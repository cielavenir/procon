#!/usr/bin/rdmd
import std.cstream;

int main(){
	int n,i,y,m,d;
	din.readf(&n);
	for(i=0;i<n;i++){
		din.readf(&y,&m,&d);
		dout.writefln("%d",(196471-(--y)*195-y/3*5-(--m)*20+(y%3-2?m/2:0)-d));
	}
	return 0;
}