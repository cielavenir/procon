#!/usr/bin/ruby
n,m,g,k=gets.split.map(&:to_i)
n*=2
pascal=[1,1]
2.step(n){pascal=[1]+pascal.each_cons(2).map{|a,b|a+b}+[1]}
p=[0]*(n+1)
p[m]=1
g.times{
	q=[0]*(n+1)
	(n+1).times{|i|
		_p=i.to_f/n
		(n+1).times{|j|
			q[j]+=p[i]*(pascal[j]*_p**j*(1-_p)**(n-j))
		}
	}
	p=q
}
puts p[0..n-k].reduce(:+)