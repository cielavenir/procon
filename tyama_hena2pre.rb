#!/usr/bin/env ruby
#coding:utf-8
#http://qiita.com/Nabetani/items/9d80de41903775296ca6
#STDOUT.sync=true
def solve(l)
	n,s=l.split(':')
	n=n.to_i
	n.to_s+':'+sprintf("%0#{s.size}x",
		(sprintf("%0#{s.size*4}b",s.to_i(16))[0,n*n]
		.chars
		.map(&:to_i)
		.each_slice(n)
		.to_a
		.transpose
		.map{|e|e.reverse*''}*''+'0'*(s.size*4-n*n)).to_i(2)
	)
end
DATA.each_with_index{|e,i|
	input,expect=e.chomp.split(' → ')
	puts 'Case '+(i+1).to_s+': '+(expect==solve(input)?'OK':'NG')
}
__END__
3:5b8 → 3:de0
1:8 → 1:8
2:8 → 2:4
2:4 → 2:1
2:1 → 2:2
3:5d0 → 3:5d0
4:1234 → 4:0865
5:22a2a20 → 5:22a2a20
5:1234567 → 5:25b0540
6:123456789 → 6:09cc196a6
7:123456789abcd → 7:f1a206734b258
7:fffffffffffff → 7:ffffffffffff8
7:fdfbf7efdfbf0 → 7:ffffffffffc00
8:123456789abcdef1 → 8:f0ccaaff78665580
9:112233445566778899aab → 9:b23da9011d22daf005d40