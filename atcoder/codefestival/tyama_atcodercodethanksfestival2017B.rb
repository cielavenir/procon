#!/usr/bin/ruby
s=gets;p (0..s.size).find{|i|t=s[i..-2];t==t.reverse}
