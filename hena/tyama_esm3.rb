#!/usr/bin/env ruby
#http://qiita.com/kunitoo/items/d39c5337d400ad53f224
#https://gist.github.com/kunitoo/76b1d56cc6ffeef9bb62

def battle(x,y)
	(x.size*y.size).times{|i|
		if x[i%x.size]!=y[i%y.size]
			if x[i%x.size]==?R
				return y[i%y.size]==?S ? x : y
			elsif x[i%x.size]==?S
				return y[i%y.size]==?P ? x : y
			elsif x[i%x.size]==?P
				return y[i%y.size]==?R ? x : y
			end
		end
	}
	y
end

if __FILE__==$0
	while gets
		#participants生成方法はデスマコロシアム(デスコロC)を流用するため、dataは降順である必要がある
		data=$_.chomp[1..-2].split(')(').reverse
		num=1
		num*=2 while num<data.size
		nil_size=num-data.size

		participants=data[0..-nil_size-1]+(nil_size==0 ? [] : (data[-nil_size..-1]+[nil]*nil_size).each_slice(nil_size).to_a.transpose.flat_map{|e|e})
		while participants.size>1
			participants_next=[]
			participants.each_slice(2){|x,y|
				if y
					participants_next<<battle(x,y)
				else
					participants_next<<x
				end
			}
			participants=participants_next
		end
		puts '('+participants[0]+')'
		STDOUT.flush
	end
end