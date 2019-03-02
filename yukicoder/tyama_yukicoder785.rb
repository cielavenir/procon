#!/usr/bin/ruby
p$<.map{|e|(e[0]==?N ? 16 : 16-e.size/2)**2}.reduce :*
