#!/usr/bin/ruby
a,b=gets.chomp.split(':').map(&:to_i)
puts '%02d:%02d'%((a*60+b+5)%1440).divmod(60)
