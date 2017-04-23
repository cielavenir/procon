#!/usr/bin/ruby
s=gets.chomp
puts s==s.reverse.tr('1234567890','##36947058')?:Yes: :No
