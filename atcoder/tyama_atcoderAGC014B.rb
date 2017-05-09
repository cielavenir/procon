#!/usr/bin/ruby
gets;puts$<.read.split.group_by{|e|e}.all?{|k,v|v.size%2<1}?:YES: :NO
