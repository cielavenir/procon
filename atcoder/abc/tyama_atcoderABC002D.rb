#!/usr/bin/ruby
h={}
#n=gets.to_i
#$<.each{|e|h[e.split.map(&:to_i)]=1}
n,m=gets.split.map(&:to_i)
m.times{
	h[gets.split.map(&:to_i)]=1
}
p [*2..n].select{|i|
	[*1..n].combination(i).any?{|a|a.combination(2).all?{|x,y|h[[x,y]]}}
}.max||1