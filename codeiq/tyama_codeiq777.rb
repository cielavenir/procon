#!/usr/bin/ruby
def chain(a)
	r=0
	while a[0]!=1
		a=a[0...a[0]].reverse+a[a[0]..-1]
		r+=1
	end
	return r
end
puts [*1..9].permutation.max_by{|e|chain(e)}*'' # 615972834
#p chain([6, 1, 5, 9, 7, 2, 8, 3, 4]) # 30