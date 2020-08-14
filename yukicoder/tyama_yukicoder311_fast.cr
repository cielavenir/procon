#!/usr/bin/env crystal
lib C;fun strtoll(s: UInt8*,p: UInt8**,b: Int32): Int64;end
N=C.strtoll(gets.not_nil!,nil,10);p (N // 3 + N // 5)*2
