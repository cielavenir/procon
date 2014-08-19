#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
puts m<2*n||4*n<m ? '-1 -1 -1' : m<3*n ? "#{3*n-m} #{m-2*n} 0" : "0 #{4*n-m} #{m-3*n}"