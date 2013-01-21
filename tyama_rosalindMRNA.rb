#!/usr/bin/ruby
table={"F"=>2,"L"=>6,"S"=>6,"Y"=>2,"C"=>2,"W"=>1,"P"=>4,"H"=>2,"Q"=>2,"R"=>6,"I"=>3,"M"=>1,"T"=>4,"N"=>2,"K"=>2,"V"=>4,"A"=>4,"D"=>2,"E"=>2,"G"=>4}
p (gets.chomp.chars.map{|e|table[e]}+[3]).reduce(1){|s,e|s=s*e%10**6}