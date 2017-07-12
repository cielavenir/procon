#!/usr/bin/ruby
n,a,b,c,d=gets.split.map &:to_i;puts (0...n).any?{|i|c*(j=n+~i)-d*i<=b-a&&b-a<=d*j-c*i}?:YES: :NO
