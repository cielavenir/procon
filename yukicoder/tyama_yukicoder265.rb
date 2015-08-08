#!/usr/bin/ruby
class Array
	def -@
		self.map(&:-@)
	end
	def +(other)
		m=[self.size,other.size].max
		m.times.map{|i|(self.size<=i ? 0 : self[i])+(other.size<=i ? 0 : other[i])}
	end
	def -(other)
		self+-other
	end
	def *(other)
		r=[]
		other.size.times{|i|
			r=r+i.times.map{0}.concat(self.map{|e|other[i]*e})
		}
		r
	end
end
def d(a)
	a.size<=1 ? [0] : 1.step(a.size-1).map{|i|i*a[i]}
end

gets
D=gets.to_i
s=gets.chomp.gsub(/(\d+)/,'[\1]').gsub('x','[0,1]').gsub('d{','d(').gsub('}',')')
A=s.count('d(')>10000 ? [0] : eval(s)
puts A.concat((D+1-A.size).times.map{0}).join(' ')
__END__
d{x}は最大10000回しか現れないので、10000回以上d{が存在したら確実に0である。