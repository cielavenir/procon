#!/usr/bin/ruby
$unit=["","Man","Oku","Cho","Kei","Gai","Jo","Jou","Ko","Kan","Sei","Sai","Gok","Ggs","Asg","Nyt","Fks","Mts"]
def _print(x,d)
	if d<$unit.size
		_print(x/10000,d+1)
		v=x%10000
		$><<'%d%s'%[v,$unit[d]] if v>0
	end
end
while(m,n=gets.split.map(&:to_i))!=[0,0]
	m=m**n
	_print(m,0)
	puts
end