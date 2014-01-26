#!/usr/bin/ruby
Z=1.96 #1.959963984540054 #scipy.stats.norm.ppf(0.975)
h=Hash.new(0);a=[]
gets
gets.split.each{|e|
	a<<e.to_i
	h[e.to_i]+=1
}
a.sort!
sum=a.reduce(:+).to_f
ave=sum/a.size
puts ave
if a.size%2==0
	puts (a[a.size/2-1]+a[a.size/2]).to_f/2
else
	puts a[a.size/2]
end
puts h.sort_by{|k,v|[-v,k]}[0][0]
sd=Math.sqrt(a.reduce(0){|s,e|s+(ave-e)**2}/(a.size))
puts sd
puts [-Z,Z].map{|e|ave+e*sd/Math.sqrt(a.size)}*' '