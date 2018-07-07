#!/usr/bin/ruby
p gets.to_i.times.map{gets.chomp.scan(/0*$/)[0].size}.min
