#!/usr/bin/ruby
#stage1
#key='12388946'.each_byte.map{|e|e}
#str='3132336F514B5152'.chars.each_slice(2).map{|e|e.join.hex}
#puts key.zip(str).map{|e,f|(e^f).chr}.join[3,5].each_byte.map{|e|e.to_s(16)}*''
# 5769726564

#stage2
#key='12300000'.each_byte.map{|e|e}
#str='7073720900020A1B'.chars.each_slice(2).map{|e|e.join.hex}
#puts key.zip(str).map{|e,f|(e^f).chr}.join
# AAA902:+

key='AAAAAAAA'.each_byte.map{|e|e}
str='7073720900020A1B'.chars.each_slice(2).map{|e|e.join.hex}
puts key.zip(str).map{|e,f|(e^f).chr}.join
# 123HACKZ => answer: HACKZ

key='123HACKZ'.each_byte.map{|e|e}
str='66776323243A0411'.chars.each_slice(2).map{|e|e.join.hex}
puts key.zip(str).map{|e,f|(e^f).chr}.join
# WEPkeyOK