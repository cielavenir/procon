#!/usr/bin/ruby
require 'bigdecimal'
$M=99
def pan(n,f)
	r=0
	h={}
	sqrt=BigDecimal(n.to_s).sqrt(99).split
	sqrt[1][(f ? 0 : sqrt[3])..99].each_char{|c|
		r+=1
		h[c.to_i]=true
		return r if (0..9).all?{|e|h.has_key?(e)}
	}
	nil
end

(1..1/0.0).each{|i|
	next if Math.sqrt(i).to_i**2==i
	if pan(i,true)==10
		puts '整数部分を含む場合:'+i.to_s
		break
	end
}
(1..1/0.0).each{|i|
	next if Math.sqrt(i).to_i**2==i
	if pan(i,false)==10
		puts '小数部分のみの場合:'+i.to_s
		break
	end
}