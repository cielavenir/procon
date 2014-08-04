#!/usr/bin/ruby
#TLE in hackerrank
$memo={}
def cycle(n) $memo[n]||=1.upto(1/0.0){|i|return i if ((10**i)-1)%n==0} end
gets.to_i.times{
	p 3.step(gets.to_i-1,2).map{|i|[i%10==5?0:-cycle(i),i]}.min[1]
}
__END__
1
1000