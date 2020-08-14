#!/usr/bin/env crystal
lib C;fun strtoll(s: UInt8*,p: UInt8**,b: Int32): Int64;end
p C.strtoll(gets.not_nil!,nil,10)//1000//gets.not_nil!.to_i*1000
