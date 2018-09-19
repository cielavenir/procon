#!/usr/bin/ruby
#https://jag2018summer-day2.contest.atcoder.jp/
a,b,c=gets.split.map &:to_i;p c.step(9<<99,10**9+7).find{|z|z%17==a&&z%107==b}
