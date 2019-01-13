#!/usr/bin/ruby
p gets=~/\[.*?\:(.*)\:.*?\]/ ? $1.count(?|)+4 : -1
