#!/usr/bin/ruby
h,m=gets.split.map(&:to_i)
h=(h%12)*60+m
r=((Rational(h,720)-Rational(m,60)).abs*360).to_f
p [r,360-r].min