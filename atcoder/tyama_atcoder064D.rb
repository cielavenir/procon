#!/usr/bin/ruby
s=gets.chop;puts (s.size%2==1)^(s[0]==s[-1])?:First: :Second
