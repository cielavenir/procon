#!/usr/bin/ruby
s=gets.chomp
t=s.downcase
i=0
gets.split.each{|c|
	if t==t=t.tr(c,c.upcase)
		break if 6==i+=1
	end
}
puts DATA.each.map{|e|e[i*7,7].strip}
puts t.tr('a-z','_').downcase.chars.zip(s.chars).map{|x,y|x=='_'?x:y}*''

__END__
+--+   +--+   +--+   +--+   +--+   +--+   +--+
|      |  o   |  o   |  o   |  o   |  o   |  o
|      |      |  |   | /|   | /|\  | /|\  | /|\
|\     |\     |\     |\     |\     |\/    |\/ \
