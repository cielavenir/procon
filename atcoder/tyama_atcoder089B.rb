#!/usr/bin/ruby
n=`tr -d ' '`.to_i;puts n==Math.sqrt(n).to_i**2?:Yes: :No
