#!/usr/bin/ruby
#https://abc096.contest.atcoder.jp/submissions/2465874
p *3.step(1499,5).select{|i|2**i%i==2}[0,gets.to_i]
