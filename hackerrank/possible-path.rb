#!/usr/bin/ruby
gets;puts$<.map{|e|a,b,c,d=e.split.map &:to_i;a.gcd(b)==c.gcd(d)?:YES: :NO}