#!/usr/bin/ruby
while gets
n=$_.to_i
print'1'
a=[1]
2.step(n){
	b=[a[0]]
	(a.size-1).times{|i|
		b<<a[i]+a[i+1]
	}
	b<<a.last
	print ' '+b*' '
	a=b
}
puts
end