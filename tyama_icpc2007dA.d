#!/usr/bin/rdmd
//domestic 2007 A in D-lang

import std.cstream;

int main(/*char [][]args*/){
  int i, n, s, ma, mi, sum;
  while(true){
    ma=0; mi=1000; sum=0;
    din.readf(&n);
    if(n==0)return 0;
    for(i=0;i<n;i++){
      din.readf(&s);
      ma=ma>s?ma:s;
      mi=mi<s?mi:s;
      sum+=s;
    }
    dout.writefln("%d",(sum-ma-mi)/(n-2));
  }
}