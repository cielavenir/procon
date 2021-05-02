#!/usr/bin/ruby
H,W=gets.split.map &:to_i
a=$<.map &:chomp
h=(0...H).select{|h|a[h].chars.any?{|c|c=='#'}}
w=(0...W).select{|w|(0...H).any?{|k|a[k][w]=='#'}}
h.each{|i|w.each{|j|print a[i][j]};puts}
