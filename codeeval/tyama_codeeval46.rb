#!/usr/bin/ruby
require'prime';while s=gets do n=s.to_i; puts Prime.each(n){|p|if p>2 then print ',' end; print p} end