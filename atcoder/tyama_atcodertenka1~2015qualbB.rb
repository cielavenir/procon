#!/usr/bin/ruby
x=0;s=gets.chop;puts s=='{}'||s.chars.any?{|c|x+=c=='{'?1:c=='}'?-1:0;c==':'&&x==1}?:dict: :set