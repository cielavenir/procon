#!/usr/bin/ruby
eval'p 0b1'+`tr LR 01`

__END__
s=gets.chomp
r=1<<s.size
s.chars.each_with_index{|c,i|r+=1<<(s.size-i-1) if c=='R'}
p r
