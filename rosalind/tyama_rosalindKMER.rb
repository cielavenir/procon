#!/usr/bin/ruby
seq=$<.drop(1).map(&:chomp)*''
#puts 'ACGT'.split('').repeated_permutation(4).map{|a|seq.size.times.count{|i|seq[i,4]==a*''}}*' '
h=Hash.new(0)
seq.split('').each_cons(4){|a|h[a*'']+=1}
puts 'ACGT'.split('').repeated_permutation(4).map{|a|h[a*'']}*' '