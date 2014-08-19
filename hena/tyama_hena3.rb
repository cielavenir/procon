#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/ord3ynode/
T={ #clockwise
	'A'=>['D','C','B'],
	'B'=>['E','A','C'],
	'C'=>['F','B','A'],
	'D'=>['A','E','F'],
	'E'=>['B','F','D'],
	'F'=>['C','D','E'],
}
STDOUT.sync=true
while gets
	curr='A';prev='B'
	print 'A'
	$_.chomp.chars{|e|
		if e=='b'
			curr,prev=prev,curr
		elsif e=='r'
			curr,prev=T[curr][(T[curr].index(prev)+2)%3],curr
		elsif e=='l'
			curr,prev=T[curr][(T[curr].index(prev)+1)%3],curr
		end
		print curr
	}
	puts
end