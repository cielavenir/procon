#!/usr/bin/ruby
h=Hash.new 0;gets;$<.each{|e|h[e]^=1};p h.values.reduce :+
