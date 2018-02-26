#!/usr/bin/ruby
n=gets.to_i
x,y=$<.map{|e|e.split.map &:to_i}.transpose
r=[0]*n
(M=250000).times{|i|
	r[ (0...n).min_by{|j|t=2*Math::PI*i/M;x[j]*Math.cos(t)+y[j]*Math.sin(t)} ]+=1
}
S=r.reduce(:+).to_f
n.times{|i|p r[i]/S}
