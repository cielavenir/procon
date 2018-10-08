#!/usr/bin/ruby
gets;a=$<.map &:to_i;x=a.reduce :^;puts x==1||(x==0&&!a.find{|e|e%2>0})?:Bob: :Alice
