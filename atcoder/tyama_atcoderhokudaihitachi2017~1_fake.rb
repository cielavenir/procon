#!/usr/bin/ruby
X,Y=2.times.map{
  v,e=gets.split.map &:to_i
  {:v=>v,:e=>e.times.map.map{gets.split.map &:to_i}}
}
X[:v].times{|i|puts '%d %d'%[i+1,i+1]}
