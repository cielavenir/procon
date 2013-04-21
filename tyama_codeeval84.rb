#!/usr/bin/ruby
while gets
str=$_.gsub(':(','S').gsub(':)','H').tr('a-z :','')
o=0
c=0
s=0
h=0
fleft=str.size.times.all?{|i|
	case str[i,1]
		when '(' then o+=1
		when ')'
			c+=1
			next if o+s-c<0
		when 'S' then s+=1
		when 'H' then h+=1
	end
	true
}
o=0
c=0
s=0
h=0
fright=(str.size-1).downto(0).all?{|i|
	case str[i,1]
		when '('
			o+=1
			next if c+h-o<0
		when ')' then c+=1
		when 'S' then s+=1
		when 'H' then h+=1
	end
	true
}
puts fleft&&fright ? 'YES' : 'NO'
end