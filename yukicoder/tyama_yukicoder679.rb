#!/usr/bin/ruby
def cycle(c,m,f,h)
	return f[c] if !f[c].nil?
	f[c]=h[c].all?{|e|
		!m.has_key?(e) && (m[e]=1;k=cycle(e,m,f,h);m.delete e;k)
	}
end
n,m=gets.split.map &:to_i
h=Hash.new{|h,k|h[k]=[]}
m.times{
g,r=gets.split.map &:to_i
h[g]=gets.split.map(&:to_i)
}
f=[nil]*-~n
(1..n).map{|i|cycle(i,{i=>1},f,h)}
p f.count(true)
