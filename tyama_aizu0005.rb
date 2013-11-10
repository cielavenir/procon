#!/usr/bin/ruby
require'rational';puts$<.map{|e|a,b=e.split.map &:to_i;a.gcdlcm(b)*' '}