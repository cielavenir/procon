#!/usr/bin/ruby
n=gets.to_i;n.times{|i|puts ?a+[*?a..?z].sample(18)*''+(i<n-1??a:?n)}
