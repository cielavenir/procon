#!/usr/bin/ruby
m={"2"=>2,"3"=>3,"4"=>4,"5"=>5,"6"=>6,"7"=>7,"8"=>8,"9"=>9,"T"=>10,"J"=>10,"Q"=>10,"K"=>10,"A"=>11}
gets.to_i.times{
	s=0
	ace=false
	m['A']=11
	gets.split.each{|e|s+=m[e];if e=='A'&&m[e]==11 then ace=true;m[e]=1 end}
	a=gets.split
	if s==21 then puts 'blackjack';next end
	a.each{|e|
		if s>17||(s==17&&!ace) then break end
		s+=m[e];if e=='A'&&m[e]==11 then ace=true;m[e]=1 end
		if s>21&&ace then s-=10;ace=false end
	}
	puts s>21?'bust':s
}