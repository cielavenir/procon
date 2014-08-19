#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
#http://nabetani.sakura.ne.jp/hena/ord24eliseq/
MAX=10000
sq=Hash[[*1..100].map{|e|[e**2,1]}]
cb=Hash[[*1..100].map{|e|[e**3,1]}]
if $0==__FILE__
	STDOUT.sync=true
	while gets
		input=$_.chomp.split('')
		a=[*1..MAX]
		input.each{|e|
			if e=='S'
				idxes=a.each.with_index.select{|f,i|sq.include?(f)}.map{|e|e.last+1}
				a=a.each.with_index.reject{|f,i|idxes.include?(i)}.map(&:first)
			elsif e=='s'
				idxes=a.each.with_index.select{|f,i|sq.include?(f)}.map{|e|e.last-1}
				a=a.each.with_index.reject{|f,i|idxes.include?(i)}.map(&:first)
			elsif e=='C'
				idxes=a.each.with_index.select{|f,i|cb.include?(f)}.map{|e|e.last+1}
				a=a.each.with_index.reject{|f,i|idxes.include?(i)}.map(&:first)
			elsif e=='c'
				idxes=a.each.with_index.select{|f,i|cb.include?(f)}.map{|e|e.last-1}
				a=a.each.with_index.reject{|f,i|idxes.include?(i)}.map(&:first)
			elsif e=='h'
				a=a.drop(100)
			else
				a=a.each.with_index(1).select{|f,i|i%e.to_i!=0}.map(&:first)
			end
		}
		puts a[0,10]*','
	end
end