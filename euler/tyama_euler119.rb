#!/usr/bin/ruby
def digitsum(n,b)
	r=0
	while n>0
		r+=n%b
		n/=b
	end
	r
end

b=gets.to_i
a=[]
(2..20000).each{|i|
	v=i
	loop{
		v*=i
		break if v>=10**100
		a<<v if digitsum(v,b)==i
	}
}
# p a.sort[29] # 248155780267521
puts a.uniq.sort*' '
__END__
10