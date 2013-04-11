#!/usr/bin/ruby
#is07kuno report10b

def accept(s,atm)
	cur = 0
	s.chars{|c|
		cur = atm[cur][c]
		if cur == nil then return false end
	}
	return atm[cur][:final] == true
end

atm = [
	{"0" => 1, "1" => 2},
	{"1" => 3},
	{"0" => 1},
	{"0" => 4, "1" => 5},
	{"0" => 5, "1" => 2},
	{"0" => 2, "1" => 1, :final => true}
]

while gets
	exit if $_.chomp=='#'
	puts accept($_.chomp,atm) ? 'Yes' : 'No'
end