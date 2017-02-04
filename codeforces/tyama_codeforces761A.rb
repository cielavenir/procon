#!/usr/bin/ruby
a,b=gets.split.map &:to_i;puts a+b>0&&(a-b).abs<2?:YES: :NO
