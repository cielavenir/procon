#!/usr/bin/ruby
_,a,b=`dd`.split;puts a.chars.zip(b.chars).join
