#!/usr/bin/ruby
H,W=gets.split.map &:to_i
m=$<.to_a
r=0
H.times{|h|W.times{|w|m[h][w]>?-&&r+=(H-1-h+w)%2+1}}
puts r%3==0?:YES: :NO
__END__
m=$<.to_a.reverse
