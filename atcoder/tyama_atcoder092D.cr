#!/usr/bin/env crystal
N=gets.not_nil!.to_i
A=gets.not_nil!.split.map &.to_i
B=gets.not_nil!.split.map &.to_i
r=0
(0..28).each{|b|
q=0;t=1<<b;a=A.map{|e|e% (2*t)}.sort
B.map{|e|e % (2*t)}.map{|e|i=(1..4).map{|j|(0...N).bsearch{|i|j*t-a[i]<=e}||N};q=(q+i[3]-i[2]+i[1]-i[0])%2}
r^=q*t
}
p r
