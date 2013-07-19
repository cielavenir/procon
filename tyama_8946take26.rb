#!/usr/bin/ruby
#Stage1: Use jsbeautifier
#Stage2:
str='Hint&#65306;&#1050;&#1086;&#1075;&#1076;&#1072; &#1044;&#1077;&#1085;&#1100; &#1057;&#1074;&#1103;&#1090;&#1086;&#1075;&#1086; &#1042;&#1072;&#1083;&#1077;&#1085;&#1090;&#1080;&#1085;&#1072;? (MM / DD)'
dec=''
while str=~/&#(\d+);/
	dec+=$`
	dec+=$1.to_i.chr('UTF-8')
	str=$'
end
puts dec+str
#Stage3: Use google translator