#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
h=[0]*30
a.each{|e|h[e]+=1}
p *h
# atcoder細則ですが、空白区切りではなく改行区切りにしてもokです
