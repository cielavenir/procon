while(l=gets.chomp)!='#'
puts l.split('|').all?{|e|a=e[1..e.size-2].split('&');a.select{|e|e[0,1]!='~'&&a.index('~'+e)}!=[]}?'no':'yes'end