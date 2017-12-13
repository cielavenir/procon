#!/usr/bin/ruby
r=1<<30
H,W=gets.split.map &:to_i
M=H.times.map{gets.split.map &:to_i}
H.times{|h|W.times{|w|
s=0;H.times{|i|W.times{|j|
s+=M[i][j]*[(h-i).abs,(w-j).abs].min
}};r=[r,s].min
}}
p r
