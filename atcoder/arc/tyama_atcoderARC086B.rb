#!/usr/bin/ruby
gets;p gets.split.map{|e|s='%b'%e;s.size+~s.rindex(?1)}.min
