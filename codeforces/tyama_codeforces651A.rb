#!/usr/bin/ruby
a,b=gets.split.map &:to_i;p a+b-((a-b)%3==0&&a*b!=1 ? 3 : 2)