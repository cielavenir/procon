#!/usr/bin/ruby
while gets do if $_=~/'(.+)'/&&$1!='<eos>' then puts $1 end end