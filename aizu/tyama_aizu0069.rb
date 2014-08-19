#!/usr/bin/ruby
def check(a,l,m,_e,n)
m-=1
l.times{|k|
	if m>0&&a[k][m-1] then m-=1
	elsif m<n-1&&a[k][m] then m+=1 end
}
return m+1==_e
end
while(n=gets.to_i)>0
m=gets.to_i
_e=gets.to_i
l=gets.to_i
a=l.times.map{gets.chomp.chars.map{|e|e=='1'}}
if check(a,l,m,_e,n) then p 0;next end
begin
l.times{|j|
	(n-1).times{|i|
		next if a[j][i]
		next if (i>0&&a[j][i-1])
		next if (i<n-2&&a[j][i+1])
		a[j][i]=true
		if check(a,l,m,_e,n) then puts "#{j+1} #{i+1}";raise "ok" end
		a[j][i]=nil
	}
}
rescue; next end
p 1
end