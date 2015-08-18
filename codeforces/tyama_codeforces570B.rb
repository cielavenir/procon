#!/usr/bin/ruby
N,M=gets.split.map(&:to_i)
p N==1 ? 1 : M-1<N-M ? M+1 : M-1