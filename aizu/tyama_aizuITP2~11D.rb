#!/usr/bin/ruby
h={};n,k=gets.split.map &:to_i
[*0...n].combination(k){|e|h[e.map{|_|1<<_}.reduce :+]=e}
puts h.sort.map{|k,v|k.to_s+':'+v.map{|e|' %d'%e}*''}
