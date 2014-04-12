#!/usr/bin/ruby
A=['()','8<','[]']
group=[gets.scan(/../),gets.scan(/../)].map{|e|e.map(&A.method(:index))}.transpose.map{|a,b|(b-a+3)%3}.group_by{|e|e}
puts({-1=>'TEAM 2 WINS',0=>'TIE',1=>'TEAM 1 WINS'}[(group[1]||[]).size<=>(group[2]||[]).size])