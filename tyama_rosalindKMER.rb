#!/usr/bin/ruby
seq=ARGF.lines.to_a[1..-1].map(&:chomp).join
#puts "ACGT".split('').repeated_permutation(4).map{|a|seq.length.times.count{|i|seq[i,4]==a.join}}.join(' ')
h=Hash.new(0)
seq.split('').each_cons(4){|a|h[a.join]+=1}
puts "ACGT".split('').repeated_permutation(4).map{|a|h[a.join]}.join(' ')