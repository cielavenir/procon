#!/usr/bin/ruby
p gets.to_i.times.map{gets.to_i}.sort.each_cons(2).map{|x,y|y-x}.min
__END__
ruby -e 'p gets.to_i.times.map{gets.to_i}.sort.each_cons(2).map{|x,y|y-x}.min'