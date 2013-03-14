#!/usr/bin/ruby
s=$<.drop(1).map(&:chomp)*''
au=[s.scan('A').count,s.scan('U').count].sort
cg=[s.scan('C').count,s.scan('G').count].sort
p (au[1]-au[0]+1..au[1]).reduce(:*)*(cg[1]-cg[0]+1..cg[1]).reduce(:*)