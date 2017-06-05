#!/usr/bin/env ruby
#http://mtsmfm.github.io/2017/06/03/doukaku-e14.html
#http://qiita.com/mtsmfm/items/89b6634f363bbf5b47f5

def parsefasta(f)
	arc={}
	seq=[]
	line=f.gets
	line.chomp!
	name=line[1..-1]
	while line=f.gets
		line.chomp!
		if line[0,1]=='>'
			arc[name]=seq
			seq=[]
			name=line[1..-1]
		else
			seq<<line.chars.to_a
		end
	end
	arc[name]=seq
	arc
end

#cf: https://github.com/cielavenir/codeiq_solutions/blob/master/thisweek_masuipeo2/tyama_codeiq3106.rb
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
T=parsefasta(DATA).values.to_a

def solve(a)
	A[0].product(*A[1..-1]).each{|e|
		# 重複あるけど気にしないことにします…
		T.each{|b|
			c=e.reduce(b){|s,f|f.call(s)}
			(0..a.size-c.size).each{|sy|
				(0..a[0].size-c[0].size).each{|sx|
					h=Hash.new{|h,k|h[k]=[]}
					c.size.times{|y|
						c[0].size.times{|x|
							if c[y][x]!='*'
								h[c[y][x]]<<a[sy+y][sx+x]
							end
						}
					}
					if h.values.flatten.uniq.size==6 && h.all?{|k,v|v.reduce(:+)==7}
						return true
					end
				}
			}
		}
	}
	false
end

while gets
	p solve($_.chomp.split(',').map{|e|e.chars.map(&:to_i)})
	STDOUT.flush
end

__END__
>1
1***
2323
1***
>2
1***
2323
*1**
>3
1***
2323
**1*
>4
1***
2323
***1
>5
*1**
2323
*1**
>6
*1**
2323
**1*
>7
21**
*323
*1**
>8
21**
*323
**1*
>9
21**
*32*
**13
>10
21**
*323
***1
>11
121**
**323
