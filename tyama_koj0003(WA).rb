#!/usr/bin/ruby
while s=gets do a,b=s.split.map(&:to_i);puts (((b+1)>>1)-(a>>1)&1)==1?"ODD":"EVEN"end