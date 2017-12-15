#!/usr/bin/ruby
gets;puts$<.partition{|e|e.to_i<0}.any?{|e|e.size<2} ? :YES : :NO
#we need to handle true/false always, so group_by cannot be used.
