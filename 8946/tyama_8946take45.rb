#!/usr/bin/ruby
#stage1
#key='12388946'.bytes.to_a
#str='3132336F514B5152'.scan(/../).map(&:hex)
#puts key.zip(str).map{|e,f|(e^f).chr}.join[3,5].each_byte.map{|e|e.to_s(16)}*''
# 5769726564

#stage2
#key='12300000'.bytes.to_a
#str='7073720900020A1B'.scan(/../).map(&:hex)
#puts key.zip(str).map{|e,f|(e^f).chr}*''
# AAA902:+

key='AAAAAAAA'.bytes.to_a
str='7073720900020A1B'.scan(/../).map(&:hex)
puts key.zip(str).map{|e,f|(e^f).chr}*''
# 123HACKZ => answer: HACKZ

key='123HACKZ'.bytes.to_a
str='66776323243A0411'.scan(/../).map(&:hex)
puts key.zip(str).map{|e,f|(e^f).chr}*''
# WEPkeyOK