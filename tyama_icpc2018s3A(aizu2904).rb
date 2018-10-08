#!/usr/bin/ruby
#https://jag2018summer-day3.contest.atcoder.jp/
r=x=0;gets.chars{|c|x+=(c==?R ? 1 : -1);x==4&&r+=1;x%4==0&&x=0};p r
