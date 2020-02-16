#!/usr/bin/ruby
N,K=gets.split.map &:to_i
begin
(0..1/0.0).each{|i|p~-N%-~K-~K*i;STDOUT.flush}
rescue;end
