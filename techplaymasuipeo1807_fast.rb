#!/usr/bin/ruby
class Array
	def rotate180
		self.reverse.map(&:reverse)
	end
	def rotate90
		self.reverse.transpose
	end
	def rotate270
		self.transpose.reverse
	end
end
A=[
	[ # 反転
		lambda{|a|a},
		lambda{|a|a.map(&:reverse)},
	],[ # 回転
		lambda{|a|a},
		lambda{|a|a.rotate90},
		lambda{|a|a.rotate180},
		lambda{|a|a.rotate270},
	]
]
n=gets.to_i
a=[[n+1,n+6,n+5],[n+8,n+4,n+0],[n+3,n+2,n+7]]
A[0].product(*A[1..-1]).each{|e|
	p x=e.reduce(a){|s,f|f.call(s)}.flatten
}
