#!/usr/bin/ruby
puts "#!/bin/bash"
print "ruby -e '"
$<.each{|e|print e.strip.gsub("'",'"')+';' if !e.strip.start_with?('#')}
puts "'"