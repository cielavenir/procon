#!/usr/bin/ruby
p`sed 1d`.split.map{|e|s='%b'%e;s.size+~s.rindex(?1)}.min
