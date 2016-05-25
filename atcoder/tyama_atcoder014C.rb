#!/usr/bin/ruby
gets;p gets.chomp.chars.group_by{|e|e}.count{|k,v|v.size&1==1}
# l=`dd`;p %w(R G B).count{|e|l.count(e)%2>0}