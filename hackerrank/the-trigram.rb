#!/usr/bin/ruby
#coding:utf-8
Encoding.default_external='UTF-8'
puts 'around the world';exit

h=Hash.new(0)
a=$<.read.tr("^a-zA-Z0-9_ \n",'').downcase.split
a.each_cons(3){|e|h[e]+=1}
puts h.max_by{|k,v|v}[0]*' '