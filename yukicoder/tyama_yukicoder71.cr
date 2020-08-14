#!/usr/bin/env crystal
lib C;fun strtoll(s: UInt8*,p: UInt8**,b: Int32): Int64;end
n=C.strtoll(gets.not_nil!,nil,10)
p n*n//4+n
