#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/orde13hextet/
#http://qiita.com/Nabetani/items/50cd05989b6e2812f879
require 'set'

M=[
[0,0],[0,1],[0,2],[0,3],[0,4],
[1,0],[1,1],[1,2],[1,3],
[2,-1],[2,0],[2,1],[2,2],[2,3],
[3,-1],[3,0],[3,1],[3,2],
[4,-2],[4,-1],[4,0],[4,1],[4,2],
]

#CCW
T=[
	[0,1],[1,0],[1,-1],[0,-1],[-1,0],[-1,1]
]
Z={
	'B'=>'004','D'=>'040','I'=>'500','J'=>'550',
	'L'=>'005','N'=>'411','O'=>'421','S'=>'051',
	'Y'=>'0131','Z'=>'415',
}

while gets
	q=$_.chomp.bytes.map{|b|b-97}
	s=q.map{|e|M[e]}
	h=Set.new()
	s.each{|e|h.add(e)}
	s.all?{|e|
		Z.each{|k,v|
			if 6.times.any?{|d|
				y,x=e
				v.chars.all?{|dd|
					d=(d+dd.to_i)%6
					y+=T[d][0]
					x+=T[d][1]
					h.include?([y,x])
				}
			}
				puts k
				break
			end
		}
	} and puts :-
	STDOUT.flush
end
