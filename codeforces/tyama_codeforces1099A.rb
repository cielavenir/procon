#!/usr/bin/ruby
w,H,U,D,V,E=$<.read.split.map &:to_i
H.downto(1){|h|
w+=h
w=[0,w-U].max if h==D
w=[0,w-V].max if h==E
}
p w
