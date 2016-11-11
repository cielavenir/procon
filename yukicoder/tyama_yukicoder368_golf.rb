#!/usr/bin/ruby
z=->x,y{r=1;y.times{r=x*r%M};r}
M=10**9+7
E=Hash.new{|h,k|h[k]=[]}
N,K=gets.split.map &:to_i
IO.popen('factor '+gets){|_|_.map{|l|l.split[1..-1].map(&:to_i).group_by(&:+@).map{|k,v|E[k]<<v.size}}}
r=1
E.each{|k,v|r=r*z[k,v.sort_by(&:-@).take(K).reduce(:+)]%M}
p r
