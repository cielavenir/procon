#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/c70417d384720a3339d6
#http://nabetani.sakura.ne.jp/hena/ord30taxi/

class TrueClass
	def to_i() 1 end
end
class FalseClass
	def to_i() 0 end
end

DIST={
	'AB'=>[1090,0],
	'AC'=>[180,0],
	'AD'=>[540,1],
	'BC'=>[960,0],
	'BG'=>[1270,0],
	'CD'=>[400,1],
	'CF'=>[200,0],
	'DE'=>[720,1],
	'DF'=>[510,1],
	'EG'=>[1050,1],
	'FG'=>[230,1],
}
METER=[
	{:dist=>995,:cost=>400},{:dist=>845,:cost=>350}
]
DIFF=[60,50]

if __FILE__==$0
	while gets
		line=$_.chomp.chars.each_cons(2).to_a
		cost=dist=0
		meter=METER[('C'<line[0][0]).to_i]
		cost=meter[:cost]
		dist=meter[:dist]
		line.each{|e|
			d,color=DIST[e.sort.join]
			dist-=d
			while dist<0
				cost+=DIFF[color]
				dist+=200
			end
		}
		p cost
		STDOUT.flush
	end
end