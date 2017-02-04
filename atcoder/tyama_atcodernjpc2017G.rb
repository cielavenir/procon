#!/usr/bin/ruby
s=gets.chars;1while s.size.downto(3).find{|i|s[i-3]<=s[i-2]&&s[i-3]+=s.delete_at(i-2)};puts s.size<3?:Yes: :No
