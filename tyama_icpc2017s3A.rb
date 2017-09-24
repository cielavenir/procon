#!/usr/bin/ruby
s=0;gets.chomp.chars{|c|c=='('?(s+=1):c==')'?(s-=1):p(s)}
