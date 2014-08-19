#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/7b08b0eb9ef84d7cfe49
#http://nabetani.sakura.ne.jp/hena/ord7xysort/
STDOUT.sync=true
class Array
	def stable_sort(idx)
		sort_by.with_index{|s,i|[s[idx],i]}
	end
end
A=[
	[4,1,4,2,1,3],
	[7,3,2,0,5,0],
	[2,3,6,0,6,7],
	[6,4,5,7,5,1],
	[3,1,6,6,2,4],
	[6,0,5,5,5,1],
]
F={
	'u'=>lambda{|a|a.stable_sort(0)},
	'v'=>lambda{|a|a.stable_sort(1)},
	'w'=>lambda{|a|a.stable_sort(2)},
	'x'=>lambda{|a|a.stable_sort(3)},
	'y'=>lambda{|a|a.stable_sort(4)},
	'z'=>lambda{|a|a.stable_sort(5)},

	'A'=>lambda{|a|a.transpose.stable_sort(0).transpose},
	'B'=>lambda{|a|a.transpose.stable_sort(1).transpose},
	'C'=>lambda{|a|a.transpose.stable_sort(2).transpose},
	'D'=>lambda{|a|a.transpose.stable_sort(3).transpose},
	'E'=>lambda{|a|a.transpose.stable_sort(4).transpose},
	'F'=>lambda{|a|a.transpose.stable_sort(5).transpose},
}
while gets
	puts $_.chomp.chars.reduce(A){|s,e|F[e][s]}[0]*''
end