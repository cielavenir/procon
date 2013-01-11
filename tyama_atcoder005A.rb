#!/usr/bin/ruby
r=0;gets;gets.chomp.chop.split.each{|e|if["TAKAHASHIKUN","Takahashikun","takahashikun"].include?(e)then r+=1 end};puts r