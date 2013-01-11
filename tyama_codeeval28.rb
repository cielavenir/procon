#!/usr/bin/ruby
while gets
a=$_.chomp.split(',')
puts a[0]=~/#{a[1].gsub('\*','+').gsub('*','.*').gsub('+','\*')}/ ? 'true' : 'false'
end