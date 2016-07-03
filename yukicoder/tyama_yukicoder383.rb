#!/usr/bin/ruby
a,b=gets.split.map &:to_i;printf"%#{b>a ??+:''}d"%[b-a]