#!/usr/bin/ruby
def pan(n,b)
	m=''
	1.step(b){|i|
		x=m+(n*i).to_s
		break if x.size>b
		m=x
	}
	1.step(b){|i| return nil unless m.index(i.to_s)}
	return m.to_i
end
n,b=gets.split.map(&:to_i)
#p 2.step(n-1).map{|e|pan(e,b)}.compact.max
puts 2.step(n-1).select{|e|pan(e,b)}
__END__
10000 9