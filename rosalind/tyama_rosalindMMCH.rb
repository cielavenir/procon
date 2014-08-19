#!/usr/bin/ruby
s=$<.drop(1).map(&:chomp)*''
au=[s.count('A'),s.count('U')].sort
cg=[s.count('C'),s.count('G')].sort
p (au[1]-au[0]+1..au[1]).reduce(:*)*(cg[1]-cg[0]+1..cg[1]).reduce(:*)