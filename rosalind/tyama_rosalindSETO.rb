#!/usr/bin/ruby
require 'json'
u=[*1..gets.to_i]
a=JSON.parse(gets.tr('{}','[]'))
b=JSON.parse(gets.tr('{}','[]'))
puts (a|b).inspect.tr('[]','{}')
puts (a&b).inspect.tr('[]','{}')
puts (a-b).inspect.tr('[]','{}')
puts (b-a).inspect.tr('[]','{}')
puts (u-a).inspect.tr('[]','{}')
puts (u-b).inspect.tr('[]','{}')