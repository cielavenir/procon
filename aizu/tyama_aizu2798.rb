#!/usr/bin/ruby
def in_(i,j)
	0<=i&&i<H && 0<=j&&j<W
end

H,W=gets.split.map(&:to_i)
a=$<.map{|e|e.chomp.chars}
H.times{|i|
	W.times{|j|
		if a[i][j]=='x'
			(-1..1).each{|i0|(-1..1).each{|j0|
				if in_(i+i0,j+j0)&&a[i+i0][j+j0]=='-'
					a[i+i0][j+j0]='.'
				end
			}}
		elsif a[i][j]=='o'
			(-1..1).each{|j0|
				if in_(i,j+j0)&&a[i][j+j0]=='-'
					a[i][j+j0]='.'
				end
			}
		end
	}
}
p a[1..-1].map{|e|e.count('-')}.reduce(0,:+)
