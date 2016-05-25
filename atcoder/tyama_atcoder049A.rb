#!/usr/bin/ruby
S,*A=`dd`.split;puts [0,*A.map(&:to_i),S.size].each_cons(2).map{|x,y|S[x...y]}*'"'