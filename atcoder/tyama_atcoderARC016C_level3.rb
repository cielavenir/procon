#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
lottery=m.times.map{
	c,cost=gets.split.map(&:to_i)
	[cost,c.times.map{a,b=gets.split.map(&:to_i);[a-1,b]}]
}.sort
if n==1 #Lv2
	p lottery.map(&:first).min
elsif lottery.map{|e|e.last.size}.max==1 #Lv3
	a=n.times.map{false}
	total=0
	lottery.each{|e|if !a[e.last[0].first]
		a[e.last[0].first]=true
		total+=e.first
		if a.all?{|e|e}
			p total
			exit
		end
	end}
elsif n==2 #Lv4: WA
	# 「それぞれの期待値を出して最小値を求めれば良い」<=違くないですか？
	a=[]
	lottery.each{|x|
		x.last.each{|e|
			a<<[e.first,x.first*100.0/e.last]
		}
	}
	p a.group_by(&:first).map{|k,v|v.map(&:last).min}
=begin
elsif m==1 #Lv5: incomplete
	cost=lottery[0].first
	p lottery[0].last.reduce(0){|s,e|
		s+=100.0/e.last
	}*cost-cost
=end
else
	raise
end