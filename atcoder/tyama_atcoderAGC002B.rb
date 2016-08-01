#!/usr/bin/ruby
a,b=gets.split.map &:to_i;puts a>0?:Positive:b>=0?:Zero:[:Negative,:Positive][b-a&1]