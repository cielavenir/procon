#!/usr/bin/ruby
def s(n) n*(n+1)/2 end
gets.to_i.times{
	n=gets.to_i-1
	p s(n/3)*3 + s(n/5)*5 - s(n/15)*15
}
__END__
1
1000