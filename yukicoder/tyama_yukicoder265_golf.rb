class Array
	def +(o) [self.size,o.size].max.times.map{|i|(self[i]||0)+(o[i]||0)} end
	def *(o)
		r=[]
		o.size.times{|i|r=r+i.times.map{0}.concat(self.map{|e|o[i]*e})}
		r
	end
end
def d(a) a.size<=1 ? [0] : 1.step(a.size-1).map{|i|i*a[i]} end
gets
D=gets.to_i
s=gets.chomp.gsub(/(\d+)/,'[\1]').gsub('x','[0,1]').gsub('d{','d(').gsub('}',')')
A=s.count('d(')>10000 ? [0] : eval(s)
puts A.concat((D+1-A.size).times.map{0}).join(' ')