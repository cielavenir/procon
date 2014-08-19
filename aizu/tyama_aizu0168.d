#!/usr/bin/rdmd
import std.cstream;

int main(){
	int i,n;
	int[] a=new int[31];
	a[0]=a[1]=1;a[2]=2;
	for(i=3;i<31;i++)a[i]=a[i-1]+a[i-2]+a[i-3];
	for(;din.readf(&n),n;)dout.writefln((a[n]+3649)/3650);
	return 0;
}