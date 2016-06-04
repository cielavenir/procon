#!/usr/bin/env ruby
#http://qiita.com/mtsmfm/items/6d9112fcc568908caaba
#http://mtsmfm.github.io/2016/06/04/doukaku-e04.html
#1630-1659

N=8

if __FILE__==$0
	while gets
		line=$_.chomp.split(':')
		a=line[0].reverse.chars.map{|e|[(e.to_i+N-1)%N,(e.to_i)%N]}
		idx1=line[1].ord-65
		(a.size-1).downto(0){|i|
			x=a[i].index(idx1)
			if x
				idx1=a[i][x^1]
				a[i][2]=true
			end
		}
		f=a.none?{|e|e[2]}
		puts N.times.select{|i|
			next false if f && i==idx1
			idx=i
			a.all?{|e|
				x=e.index(idx)
				!x || (!e[2] && idx=e[x^1])
			}
		}.map{|e|(e+65).chr}*''
		STDOUT.flush
	end
end