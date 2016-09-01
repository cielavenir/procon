def bmi(kg,m)
	kg/m/m
end
a,b,c,d=gets.downcase.scan(/([\d'"\.]+)|([a-zA-Z]+)/).map{|e|e.compact[0]}
if a.scan(/\d/).empty?
	a,b=b,a
end
if c.scan(/\d/).empty?
	c,d=d,c
end
if b.end_with?('g')
	a,c=c,a
	b,d=d,b
end
a=a.to_f
a*=0.3048/12 if b=='in'
a*=0.3048 if b=='ft'
a*=0.9144 if b=='yd'
a*=1000 if b=='km'
a/=100 if b=='cm'
a/=1000 if b=='mm'
c=c.to_f
c*=1000 if d=='t'
c/=1000 if d=='g'
c/=1000000 if d=='mg'
c*=0.45359237 if d=='lb' || d=='lbs'
p bmi(c,a)