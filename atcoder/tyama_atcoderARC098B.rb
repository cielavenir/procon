#!/usr/bin/ruby
gets;s=gets.chomp
a=[r=o=q=0]*26
s.each_byte{|b|a[b-97]+=1;q|=1<<b-97}
s.each_byte{|b|o|=1<<b-97;q^=1<<b-97 if 0==a[b-97]-=1;r=[r,(o&q).to_s(2).count(?1)].max}
p r
