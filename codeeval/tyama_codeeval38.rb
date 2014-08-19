#!/usr/bin/ruby
while gets
n,s=$_.chomp.split(',')
puts s.split('').repeated_permutation(n.to_i).map(&:join).uniq.sort*','
end