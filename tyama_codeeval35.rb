#!/usr/bin/ruby
while gets
a=$_.chomp.split('@')
p a.size==2 && a[1][0,1]!='.' && a[1][a.size-1,1]!='.' && a[1].split('.').size>1
end