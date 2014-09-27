#!/usr/bin/ruby
T={'2'=>2,'3'=>3,'4'=>4,'5'=>5,'6'=>6,'7'=>7,'8'=>8,'9'=>9,'T'=>10,'J'=>11,'Q'=>12,'K'=>13,'A'=>14}
def solve(_cards)
	cards=_cards.map{|e|[T[e[0,1]],e[1,1]]}.sort
	number=cards.map{|e|e[0]}.uniq
	if cards.none?{|e|e[1]!=[0][1]} #flash
		if cards[0][0]==10&&cards[1][0]==11&&cards[2][0]==12&&cards[3][0]==13&&cards[4][0]==14
			return [0,cards.reverse.map(&:first)]
		elsif 4.times.all?{|i|cards[i+1][0]-cards[i][0]==1}
			return [-1,cards.reverse.map(&:first)]
		else
			return [-4,cards.reverse.map(&:first)]
		end
	elsif 4.times.all?{|i|cards[i+1][0]-cards[i][0]==1}
		return [-5,cards.reverse.map(&:first)]
	end
	size=cards.group_by{|e|e[0]}.map{|k,v|[v.size,k]}.sort
	if size.map(&:first)==[1,4]
		return [-2,size.reverse.map(&:last)]
	elsif size.map(&:first)==[2,3]
		return [-3,size.reverse.map(&:last)]
	elsif size.map(&:first)==[1,1,3]
		return [-6,size.reverse.map(&:last)]
	elsif size.map(&:first)==[1,2,2]
		return [-7,size.reverse.map(&:last)]
	elsif size.map(&:first)==[1,1,1,2]
		return [-8,size.reverse.map(&:last)]
	else
		return [-9,size.reverse.map(&:last)]
	end
end

if __FILE__==$0
	r=0
	while gets
		a=$_.split
		x,y=a.each_slice(5).map{|e|solve(e)}
		r+=1 if (x<=>y)==1 # x is bigger than y literally
	end
	p r
end