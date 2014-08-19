#!/usr/bin/ruby
n,t=gets.split.map(&:to_i)
x=0;y=0
n.times{
	card,rare,rate=gets.split
	x+=rate.to_i if card.include?('Alicia')&&rare!='N'
	y+=rate.to_i
}
p (t-t/10).to_f*x/y