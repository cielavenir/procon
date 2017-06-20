#!/usr/bin/ruby
n,*a=`dd`.split.map(&:to_i)
a.sort!
mi,ma=a[0],a[-1]
if ma-mi>1 || n<=ma || mi<1
	puts :No
elsif ma-mi==0 && (mi==n-1||2*mi<=n)
	puts :Yes
elsif ma-mi==1 && (x=(0...n).bsearch{|e|a[e]==ma}||n;x<ma&&2*(ma-x)<=n-x)
	puts :Yes
else
	puts :No
end
