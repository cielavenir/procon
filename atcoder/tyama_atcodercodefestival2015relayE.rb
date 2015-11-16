#!/usr/bin/ruby
f=->(h,m){h*60+m}
H,M,h,m=$<.read.split.map &:to_i
h0,m0=h<=6?0:(h+6)%12,m<=30?0:(m+30)%60
puts f[H,M]>=[f[h,m],f[h0,m0]].min ? :Yes: :No