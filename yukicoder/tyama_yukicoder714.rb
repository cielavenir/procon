#!/usr/bin/ruby
def parse(a)
	h=Hash.new 0
	a.each{|e|h[e]+=1}
	h
end
l=21.times.map{Hash.new 0}
gets.to_i.times{
	a=gets.split
	if a[0]==?0
		l[a[1].to_i]=parse(a[3..-1])
	elsif a[0]==?1
		p (1..20).find{|i|
			l[i][a[1]]>0 && l[i][a[1]]-=1
		}||-1
	elsif a[0]==?2
		l[a[1].to_i]=Hash.new 0
	end
}
