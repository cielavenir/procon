#!/usr/bin/ruby
1000.times{
sy,sx,gy,gx=gets.split.map(&:to_i)
res = (sy-gy>0 ? 'U' : 'D')*((sy-gy).abs) + (sx-gx>0 ? 'L' : 'R')*((sx-gx).abs)
#puts res.chars.shuffle*''
puts res
STDOUT.flush
score=gets.to_i
# learn...
}
