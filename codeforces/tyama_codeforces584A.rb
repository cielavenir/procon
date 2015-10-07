#!/usr/bin/ruby
N,T=gets.split.map(&:to_i)
puts T==10?N==1?-1:?1*~-N+?0:T.to_s*N