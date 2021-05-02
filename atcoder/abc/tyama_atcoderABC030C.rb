#!/usr/bin/ruby
(n,m),(x,y),a,b=$<.map{|e|e.split.map &:to_i}
i=j=r=0
while j<m&&i<n
	j+=1 while j<m&&b[j]<a[i]+x
	if j<m
		r+=1
		i+=1 while i<n&&a[i]<b[j]+y
	end
end
p r

__END__
(n,m),(x,y),a,b=$<.map{|e|e.split.map &:to_i};i=j=r=0;(j+=1 while j<m&&a[i]+x>z=b[j];i+=1 while i<n&&z+y>a[i]if j<m&&r+=1)while j<m&&i<n;p r