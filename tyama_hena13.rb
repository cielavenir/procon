#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/936e7885f4c607472060
#http://nabetani.sakura.ne.jp/hena/ord13blocktup/
STDOUT.sync=true
while gets
	n=0
	# 83141310145169154671122 => [[8,3,1,4,1,3,1],[1,4,5,1,6,9,1,5,4,6,7,1,1,2,2]]
	$_.chomp.split('0').map{|e|e.split('').map(&:to_i)}.each{|a|
		2.step(a.max||0){|i|
			b=a.each_with_index.select{|e|e[0]>=i} # [8,3,1,4,1,3,1] => [[8,0],[3,1],[1,2],[4,3],[1,4],[3,5],[1,6]]
			n+=b.last[1]-b.first[1]-1-(b.size-2) # n+=0 if b.size==1
		}
	}
	puts n
end