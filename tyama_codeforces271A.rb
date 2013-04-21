#!/usr/bin/ruby
(gets.to_i+1..1/0.0).each{|i|if i.to_s.chars.group_by{|e|e}.size==4 then p i;exit end}