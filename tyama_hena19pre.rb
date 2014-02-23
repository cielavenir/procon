#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/0a711729fdea28b1c30b
#http://nabetani.sakura.ne.jp/hena/ord19sanwa/
STDOUT.sync=true
while gets
	a=$_.split(',').map(&:to_i).sort
	result=[*1..a.last].combination(3).lazy.take_while{|b|b[0]<=a[0]}.select{|b|
		c=1.step(3).flat_map{|i|b.repeated_combination(i).map{|e|e.reduce(:+)}}
		a&c==a
	}.to_a
	if result.size==1
		puts result[0]*','
	elsif result.size==0
		puts :none
	else
		puts :many
	end
end