#!/usr/bin/ruby
s=gets;puts %w(Bachelor Master Doctor).find{|e|e[0]==s[2]}+' '+s[0,2]