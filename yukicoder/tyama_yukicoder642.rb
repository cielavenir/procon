#!/usr/bin/ruby
s=(gets.to_i-1).to_s 2;p s[0]==?0?0:s.size+s.count(?0)
