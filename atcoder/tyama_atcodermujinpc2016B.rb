#!/usr/bin/ruby
a,b,c=gets.split.map(&:to_f).sort;p Math::PI*((a+b+c)**2-[c-a-b,0].max**2)