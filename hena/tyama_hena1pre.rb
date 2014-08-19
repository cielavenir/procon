#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/cbc3af152ee3f50a822f
#STDOUT.sync=true
T={'2'=>2,'3'=>3,'4'=>4,'5'=>5,'6'=>6,'7'=>7,'8'=>8,'9'=>9,'1'=>10,'J'=>11,'Q'=>12,'K'=>13,'A'=>14}
while gets
	a=$_.chomp.gsub('0','').scan(/../).map{|e|[T[e[1,1]],e[0,1]]}.sort
	size=a.group_by{|e|e[0]}.values.map(&:size).sort
	if size==[1,4]
		puts '4K'
	elsif size==[2,3]
		puts 'FH'
	elsif size==[1,1,3]
		puts '3K'
	elsif size==[1,2,2]
		puts '2P'
	elsif size==[1,1,1,2]
		puts '1P'
	else
		puts '--'
	end
end