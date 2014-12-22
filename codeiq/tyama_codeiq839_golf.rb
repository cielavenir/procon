#fails on "exercise"
puts$<.map{|l|l.chomp!;(l.size%2==1?'X':l.scan(/../).map{|e|e[0]*(e[1].ord-96)}*'')+':'+l}