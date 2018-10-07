#!/usr/bin/ruby
a=gets.chomp;n=a.size/2;puts a[0,n]==a[n..-1]?:YES: :NO
