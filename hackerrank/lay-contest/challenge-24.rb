#!/usr/bin/ruby
gets.to_i.times{
    r,c,a,b=gets.split.map(&:to_i)
    z=0
    r.times{gets.split.map(&:to_i).each{|e|
        z+=e*b if e>0
        z-=e*a if e<0
    }}
    p z
}