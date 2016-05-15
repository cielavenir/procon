#!/usr/bin/ruby
gets;p gets.chomp.chars.group_by{|e|e}.count{|k,v|v.size&1==1}
# gets p;p %w(R G B).count{|e|$_.count(e)%2==1}