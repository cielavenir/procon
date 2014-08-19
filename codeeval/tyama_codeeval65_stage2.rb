#!/usr/bin/ruby
#pipe from tyama_codeeval65_stage1.c
h={}
while gets
h[$_.chomp]=1
end
puts '#!/usr/bin/ruby'
print 'h='
p h
puts 'while gets do puts h[$_.chomp] ? "True" : "False" end'