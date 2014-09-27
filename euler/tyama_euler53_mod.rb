#!/usr/bin/ruby
N,K=gets.split.map(&:to_i)
a=[1,1]
s=0
2.step(N){
	a=[1]+a.each_cons(2).map{|x,y|x+y}+[1]
	s+=a.count{|e|e>K}
}
p s
__END__
100 1000000