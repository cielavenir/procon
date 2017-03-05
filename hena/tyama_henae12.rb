#!/usr/bin/env ruby
#http://mtsmfm.github.io/2017/03/04/doukaku-e12.html
#http://qiita.com/mtsmfm/items/d307c7b884cd86621262

T={
	'I'=>[[0],[4]],
	'L'=>[[0,0],[3,1]],
	'O'=>[[0,0],[2,2]],
	'S'=>[[0,0,1],[1,2,2]],
	'T'=>[[1,0,1],[2,2,2]],
}
while gets
	h=Hash.new 0
	$_.scan(/(\d+)([ILOST])/).each{|x,y|
		x=x.to_i
		y=T[y]
		base=y[0].size.times.map{|i|
			h[x+i]-y[0][i]
		}.max
		y[0].size.times{|i|
			h[x+i]=base+y[1][i]
		}
	}
	p h.values.max
	STDOUT.flush
end
