#!/usr/bin/ruby
while s=gets do puts s.chomp.split(/,/).uniq*','end