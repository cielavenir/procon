#!/usr/bin/ruby
a,b,c=gets.split.map &:to_f;l=Math.hypot a,b;p a-(l-c)*a/(l+c)
