#!/usr/bin/env crystal
n=gets.not_nil!.to_i
x,y=n.times.map{gets.not_nil!.split.map &.to_i}.to_a.transpose
r=[0]*n
(m=250000).times{|i|
	r[ (0...n).min_by{|j|t=2*Math::PI*i/m;x[j]*Math.cos(t)+y[j]*Math.sin(t)} ]+=1
}
s=r.sum.to_f
n.times{|i|p r[i].fdiv s} # / is not ok due to Crystal version.
