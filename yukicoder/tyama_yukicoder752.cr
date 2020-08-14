#!/usr/bin/env crystal
lib C;fun strtoll(s: UInt8*,p: UInt8**,b: Int32): Int64;end
M={0=>0_i64}
def c(o,n);M[n]||=c(o,0+(m=o//-~(o//n)))+(o%n+o%-~m)*(n-m)//2 end
o=C.strtoll(gets.not_nil!.split[0],nil,10)
ARGF.each_line{|e|l,r=e.split.map &.to_i;puts c(o,r)-c(o,l-1)}
