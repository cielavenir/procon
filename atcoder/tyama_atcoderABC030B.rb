#!/usr/bin/ruby
h,m=gets.split.map &:to_f
p [r=(h%12*30-m*5.5).abs,360-r].min

__END__
h=h%12*60+m
((h/720-m/60).abs*360).to_f