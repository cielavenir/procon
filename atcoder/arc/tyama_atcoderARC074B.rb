#!/usr/bin/ruby
_,n=gets.split.map &:to_i;n+=2;puts z=?#*n,*$<.map{|s|?#+s.chop+?#},z
