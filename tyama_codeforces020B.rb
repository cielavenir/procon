(a,b,c)=gets.split.map{|i|i=i.to_i}
if a==0
  if b==0 then puts c==0?"-1":"0";exit end
  puts "1";p -c.to_f/b;exit
end
if (d=b*b-4*a*c)<0 then puts "0";exit end
if d==0 then puts "1";p -b.to_f/2/a;exit end
puts "2"
if a<0 then a=-a;b=-b;c=-c end
p (-b-Math.sqrt(d))/2/a,(-b+Math.sqrt(d))/2/a