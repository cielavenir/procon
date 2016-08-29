#!/usr/bin/ruby
s=gets.chomp
p ['a1','a8','h1','h8'].include?(s) ? 3 : s=~/[ah18]/ ? 5 : 8