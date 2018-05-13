#!/usr/bin/ruby
f=->x,y{x*y==0||(x%2==0&&f[x/2,y-1])||(y%2==0&&f[x-1,y/2])}
puts f[*gets.split.map(&:to_i)]?:Yes: :No
