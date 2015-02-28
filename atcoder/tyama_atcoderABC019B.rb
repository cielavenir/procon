#!/usr/bin/ruby
print *gets.scan(/(.)(\1*)/).map{|x,y|x+(y.size+1).to_s},$/