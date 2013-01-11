#!/usr/bin/ruby
p 2.step(199999).select{|e|e.to_s.split('').map{|e|e.to_i**5}.reduce(&:+)==e}.reduce(&:+)