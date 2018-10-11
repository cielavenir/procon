#!/usr/bin/ruby
a,b,c=$<.map &:to_i;puts a==1?'Hello World':b+c
