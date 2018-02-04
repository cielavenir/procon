#!/usr/bin/ruby
def q(n)
	($><<n<<"\n").flush
	(c=gets[0])==?V && exit
	c==?M
end
n=gets.to_i
pr=q pri=0
(1...n).bsearch{|i|
	cu=q i
	f=((i%2==pri%2)^(i<pri)) == (cu!=pr)
	pr=cu
	pri=i
	f
}
