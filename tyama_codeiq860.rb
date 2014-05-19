#!/usr/bin/ruby
PROBLEM='READ + WRITE + TALK == SKILL'
HEAD='RWTS'
#PROBLEM='We * love == CodeIQ'
#HEAD='WlC'
A=PROBLEM.chars.select{|c|([*'A'..'Z']+[*'a'..'z']).include?(c)}.uniq
if A.size>10
	puts 'PROBLEM could be wrong'
	exit
end
[*0..9].permutation(A.size){|a|
	h=Hash[*[A,a].transpose.flatten(1)]
	next if HEAD.chars.any?{|c|h[c]==0}
	str=PROBLEM.chars.map{|c|h[c]||c}*''
	puts str if eval(str)
}
__END__
1632 + 41976 + 7380 == 50988
2543 + 72065 + 6491 == 81099
4905 + 24689 + 8017 == 37611
5094 + 75310 + 1962 == 82366
5096 + 35710 + 1982 == 42788
5180 + 65921 + 2843 == 73944
5270 + 85132 + 3764 == 94166
7092 + 37510 + 1986 == 46588
7092 + 47310 + 1986 == 56388
9728 + 19467 + 6205 == 35400