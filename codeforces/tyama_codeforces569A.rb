#!/usr/bin/ruby
t,s,q=gets.split.map(&:to_i)
i=0
while s<t
	s*=q
	i+=1
end
p i
__END__
s*q**i>=t
q**i>=t/s
i>=Math.log(t/s,q)
# => p Math.log(t/s,q).ceil