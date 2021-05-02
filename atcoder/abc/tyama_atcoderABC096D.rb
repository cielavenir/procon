#!/usr/bin/ruby
i=3;gets.to_i.times{i+=5;2**i%i==2?p(i):redo}
__END__
require'prime';p *Prime.each(1499).select{|e|e%5>3}[0,gets.to_i]
require'prime';p *3.step(1499,5).select(&:prime?)[0,gets.to_i]
#https://abc096.contest.atcoder.jp/submissions/2465874
p *3.step(1499,5).select{|i|2**i%i==2}[0,gets.to_i]
