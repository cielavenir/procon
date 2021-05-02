#!/usr/bin/ruby
*a,k=$<.map &:to_i;puts a[-1]-a[0]>k ?':(':'Yay!'
