#!/usr/bin/ruby
N,K=gets.split.map(&:to_i)
c=Hash.new{|h,k|h[k]=[]}
r={}
1.upto(N-1){|i|
	k=(i**3).to_s.chars.sort
	c[k].push(i**3)
	if c[k].size==K
		r[c[k][0]]=1
	elsif c[k].size>K
		r.delete(c[k][0])
	end
}
puts r.keys.sort
__END__
9000 5