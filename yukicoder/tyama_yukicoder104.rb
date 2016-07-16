#!/usr/bin/ruby
p (?R+gets).tr('LR','01').to_i 2

__END__
s=gets.chomp
r=1<<s.size
s.chars.each_with_index{|c,i|r+=1<<(s.size-i-1) if c=='R'}
p r