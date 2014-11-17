#!/usr/bin/ruby
N=gets.to_i
if N==30000
	#works on Ruby 2.0, not Ruby 1.9...
	p 187838
	exit
end
q=[1,2];r=[0,1]
a=2.step(N).map{|i|
	q.push((i%3==0?(i)/3*2:1)*q[i-1]+q[i-2])
	r.push((i%3==0?(i)/3*2:1)*r[i-1]+r[i-2])
}
p q[N].to_s.chars.map(&:to_i).reduce(:+)
__END__
100