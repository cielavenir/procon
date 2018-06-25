#!/usr/bin/ruby
s=gets;puts s.to_i%s.chars.map(&:to_i).reduce(:+)<1?:Yes: :No
