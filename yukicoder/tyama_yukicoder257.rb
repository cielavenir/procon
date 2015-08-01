#!/usr/bin/ruby
N,K=gets.split.map &:to_i
9.times{|i|p~-N%-~K-~K*i}