#!/usr/bin/ruby
a,b,c,k=gets.split.map &:to_i;p k%2>0?b-a:a-b
#eval"A,B,C,K="+gets.split*?,;p K%2>0?B-A : A-B
