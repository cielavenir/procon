#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
p a.sort_by(&:-@).find{|e|e<0||Math.sqrt(e).to_i**2!=e}
